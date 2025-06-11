from mrjob.job import MRJob
class SongsPlayedPerDay(MRJob):

    def mapper(self, _, line):
        # Split the CSV line into fields
        song_id=' '
        username, date, song_id = line.strip().split(',')
        song_id=list(song_id.split(' '))
        for song in song_id:
              yield(song,1)

    def combiner(self,songs,value):
       yield(songs,sum(value))
    def reducer(self,song,value):
        yield(song,sum(value))
        
if __name__ == '__main__':
    SongsPlayedPerDay.run()
