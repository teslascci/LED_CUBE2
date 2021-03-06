#ifndef SongBuzzer_h
#define SongBuzzer_h
 
#include "Arduino.h"
#include "WavePattern.h"
#include "ExplosionPattern.h"
#include "OpenWindows.h"
 
class LedCubeBuzzer
{
 
public:
 
  struct Note
  {
    int num;
    int frequency;
    int period;
    int beat;
    long play_time = 0;
    long max_play_time = 0;
  };
 
  LedCubeBuzzer(int pin, LedPattern::PatternSet* set);
  ~LedCubeBuzzer();
  boolean hasExpired();
  void setNote(Note* note);
  void playNote();
  void lightDelay(int targetdelay);
  Note* getNote();
  void disableSound();
  void enableSound();
  void stop();
 
private:
  Note* _note;
  int _pin;
  boolean expired;
  long _time;
  int patternIndex = 0;
  LedPattern::PatternSet * _patterns;
  boolean _sound = true;

};
 
#endif
