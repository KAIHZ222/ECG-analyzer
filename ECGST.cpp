#include "ECGST.h"
#include <cstdlib>
#include <cstdio>

ECGST::ECGST (void) { }

ECGST::~ECGST (void) { }

double ECGST::Interval::thresh = 0.05;

ECGST::Interval::Interval(int iso, int j, int st, double sl, double of) :
  isopoint(iso), jpoint(j), stpoint(st), slope(sl), offset(of)
{ }

bool ECGST::Interval::higher(const double &thresh) const
{
  return offset < -1*thresh;
}

bool ECGST::Interval::lower(const double &thresh) const
{
  return offset > thresh;
}

bool ECGST::Interval::normal(const double &thresh) const
{
  return !(lower(thresh) || higher(thresh));
}

std::pair< int, int > ECGST::Interval::span() const
{
  //TODO: Smarter span, independent from jpoint and stpoint
  return std::make_pair(jpoint - 50, stpoint+20);
}


std::pair< int, int > ECGST::Episode::span() const
{
  return std::make_pair(start-40, end+10);
}


const ECGST::Episode& ECGST::getEpisodeAt(int i) const
{
  return episodes.at(i);
}

const ECGST::Interval& ECGST::getIntervalAt(int i) const
{
  return intervals.at(i);
}


void ECGST::addInterval(const ECGST::Interval& interval)
{
  intervals.push_back(interval);
}

void ECGST::addEpisode(const ECGST::Episode& ep)
{
  episodes.push_back(ep);
}


const std::vector< ECGST::Interval >& ECGST::getIntervals() const
{
 return intervals;
}

const std::vector< ECGST::Episode >& ECGST::getEpisodes() const
{
  return episodes;
}



ECGST::Episode::Episode(int s, int e):
  start(s), end(e)
{

}

std::pair< int, int > ECGST::getIntervalBeginAndEnd(int i) const
{
  return intervals.at(i).span();
}

std::pair< int, int > ECGST::getEpisodeBeginAndEnd(int i) const
{
  return episodes.at(i).span();
}


