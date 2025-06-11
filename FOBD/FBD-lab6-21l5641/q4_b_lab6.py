from mrjob.job import MRJob
class SongsPlayedPerDay(MRJob):

    def mapper(self, _, line):
        # Split the CSV line into fields
        song_id=' '
        username, date, song_id = line.strip().split(',')
        song_id=list(song_id.split(' '))
        h=len(song_id)
        yield (date,h)

    def reducer(self,date,noOfsongs):
        yield(date,sum(noOfsongs))
    def reducer_final(self,date,noOfsongs):
        count=len(noOfsongs)
        totalsongs=sum(noOfsongs)
        avg_songs_per_day=totalsongs/count
        yield('average no of songs',avg_songs_per_day)

if __name__ == '__main__':
    SongsPlayedPerDay.run()
