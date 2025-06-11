
from mrjob.job import MRJob
class SongsPlayedPerDay(MRJob):

    def mapper(self, _, line):
        # Split the CSV line into fields
        song_id=' '
        username, date, song_id = line.strip().split(',')
        song_id=list(song_id.split(' '))
        h=int(len(song_id))
        yield(username,h)
    def combiner(self, key, values):
          yield(key,sum(values))
    def reducer(self, key, values):
        val=max(values)
        for value in values:
            if value == val:
                yield(key, value)
if __name__ == '__main__':
    SongsPlayedPerDay.run()
