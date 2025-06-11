
from mrjob.job import MRJob
class SongsPlayedPerDay(MRJob):

    def mapper(self, _, line):
        # Split the CSV line into fields
        song_id=' '
        username, date, song_id = line.strip().split(',')
        song_id=list(song_id.split(' '))
        h=len(song_id)
        yield (date,h)

   # def combiner(self,date,noOfsongs):
    #    yield(date,sum(noOfsongs))
    def reducer(self,date,totalsongs):
        yield(date,sum(totalsongs))
        
if __name__ == '__main__':
    SongsPlayedPerDay.run()

'''
from mrjob.job import MRJob
class SongsPlayedPerDay(MRJob):

    def mapper(self, _, line):
        # Split the CSV line into fields
        username, date, song_id = line.strip().split(',')
        song_ids = song_id.split(' ')
        yield date, len(song_ids)  # Emit date and the number of songs played on that day

    def reducer(self, date, songs_played):
        total_songs = sum(songs_played)  # Total songs played on this date
        yield None, total_songs  # Emit None as key to collect all song counts

    def reducer_final(self, _, song_counts):
        total_songs = 0
        total_days = 0
        for count in song_counts:
            total_songs += count
            total_days += 1  # Count the total number of days
        avg_songs_per_day = total_songs / total_days
        yield 'Average Songs Played Per Day', avg_songs_per_day

if __name__ == '__main__':
    SongsPlayedPerDay.run()

'''
