import ns.applications
import ns.core
import ns.internet
import ns.network
import ns.point_to_point
import ns.flow_monitor  # Import the FlowMonitor module

# Create nodes
nodes = ns.network.NodeContainer()
nodes.Create(4)
print("Nodes created.")

# Set up PointToPoint links with given bandwidth, delay, and queue size
p2p_0_2 = ns.point_to_point.PointToPointHelper()
p2p_0_2.SetDeviceAttribute("DataRate", ns.core.StringValue("2Mbps"))
p2p_0_2.SetChannelAttribute("Delay", ns.core.StringValue("10ms"))
p2p_0_2.SetQueue("ns3::DropTailQueue", "MaxSize", ns.core.StringValue("10p"))
print("Link 0-2 set up with 2Mbps and 10ms delay, DropTail queue of size 10 packets.")

p2p_1_2 = ns.point_to_point.PointToPointHelper()
p2p_1_2.SetDeviceAttribute("DataRate", ns.core.StringValue("2Mbps"))
p2p_1_2.SetChannelAttribute("Delay", ns.core.StringValue("10ms"))
p2p_1_2.SetQueue("ns3::DropTailQueue", "MaxSize", ns.core.StringValue("10p"))
print("Link 1-2 set up with 2Mbps and 10ms delay, DropTail queue of size 10 packets.")

p2p_2_3 = ns.point_to_point.PointToPointHelper()
p2p_2_3.SetDeviceAttribute("DataRate", ns.core.StringValue("1.7Mbps"))
p2p_2_3.SetChannelAttribute("Delay", ns.core.StringValue("20ms"))
p2p_2_3.SetQueue("ns3::DropTailQueue", "MaxSize", ns.core.StringValue("10p"))
print("Link 2-3 set up with 1.7Mbps and 20ms delay, DropTail queue of size 10 packets.")

# Install network devices on the nodes
devices_0_2 = p2p_0_2.Install(nodes.Get(0), nodes.Get(2))
devices_1_2 = p2p_1_2.Install(nodes.Get(1), nodes.Get(2))
devices_2_3 = p2p_2_3.Install(nodes.Get(2), nodes.Get(3))
print("Devices installed on nodes.")

# Install internet stack on all nodes
stack = ns.internet.InternetStackHelper()
stack.Install(nodes)
print("Internet stack installed on all nodes.")

# Assign IP addresses
address = ns.internet.Ipv4AddressHelper()
address.SetBase(ns.network.Ipv4Address("10.1.1.0"), ns.network.Ipv4Mask("255.255.255.0"))
interfaces_0_2 = address.Assign(devices_0_2)
print("IP addresses assigned for link 0-2.")

address.SetBase(ns.network.Ipv4Address("10.1.2.0"), ns.network.Ipv4Mask("255.255.255.0"))
interfaces_1_2 = address.Assign(devices_1_2)
print("IP addresses assigned for link 1-2.")

address.SetBase(ns.network.Ipv4Address("10.1.3.0"), ns.network.Ipv4Mask("255.255.255.0"))
interfaces_2_3 = address.Assign(devices_2_3)
print("IP addresses assigned for link 2-3.")

# TCP setup with FTP traffic (from n1 to n3)
tcp_sink = ns.applications.PacketSinkHelper("ns3::TcpSocketFactory", ns.network.InetSocketAddress(interfaces_2_3.GetAddress(1), 8080))
sinkApp = tcp_sink.Install(nodes.Get(3))
sinkApp.Start(ns.core.Seconds(0.0))
sinkApp.Stop(ns.core.Seconds(5.0))
print("TCP sink application installed on node 3.")

tcp_source = ns.applications.BulkSendHelper("ns3::TcpSocketFactory", ns.network.InetSocketAddress(interfaces_2_3.GetAddress(1), 8080))
tcp_source.SetAttribute("MaxBytes", ns.core.UintegerValue(0))
sourceApp = tcp_source.Install(nodes.Get(1))
sourceApp.Start(ns.core.Seconds(0.5))
sourceApp.Stop(ns.core.Seconds(4.0))
print("TCP source application with FTP traffic installed on node 1.")

# UDP setup with CBR traffic (from n0 to n3)
udp_client = ns.applications.OnOffHelper("ns3::UdpSocketFactory", ns.network.InetSocketAddress(interfaces_2_3.GetAddress(1), 9))
udp_client.SetAttribute("PacketSize", ns.core.UintegerValue(1024))
udp_client.SetAttribute("DataRate", ns.network.DataRateValue(ns.network.DataRate("100Kb/s")))
clientApps = udp_client.Install(nodes.Get(0))
clientApps.Start(ns.core.Seconds(0.1))
clientApps.Stop(ns.core.Seconds(4.5))
print("UDP client application with CBR traffic installed on node 0.")

# UDP sink
udp_sink = ns.applications.PacketSinkHelper("ns3::UdpSocketFactory", ns.network.InetSocketAddress(ns.network.Ipv4Address.GetAny(), 9))
sinkApp = udp_sink.Install(nodes.Get(3))
sinkApp.Start(ns.core.Seconds(0.0))
sinkApp.Stop(ns.core.Seconds(5.0))
print("UDP sink application installed on node 3.")

# Enable flow monitoring
flowmon_helper = ns.flow_monitor.FlowMonitorHelper()
monitor = flowmon_helper.InstallAll()
print("Flow monitor installed on all nodes.")

# Run the simulation
ns.core.Simulator.Stop(ns.core.Seconds(5.0))
ns.core.Simulator.Run()

# Retrieve and display flow statistics
monitor.CheckForLostPackets()
classifier = flowmon_helper.GetClassifier()
for flow_id, flow_stats in monitor.GetFlowStats():
    flow_info = classifier.FindFlow(flow_id)
    # Identify TCP and UDP flows for coloring
    flow_type = "TCP" if flow_info.protocol == 6 else "UDP" if flow_info.protocol == 17 else "Unknown"
    color = "Blue" if flow_type == "TCP" else "Red" if flow_type == "UDP" else "Unknown"
    print("Flow {} ({} -> {}) [{} flow]".format(flow_id, flow_info.sourceAddress, flow_info.destinationAddress, color))
    print("  Tx Packets: {}".format(flow_stats.txPackets))
    print("  Rx Packets: {}".format(flow_stats.rxPackets))
    print("  Throughput: {:.2f} Mbps".format(flow_stats.rxBytes * 8.0 / 5.0 / 1024 / 1024))
    print("  Lost Packets: {}".format(flow_stats.lostPackets))

# Clean up
ns.core.Simulator.Destroy()
print("Simulation finished.")
