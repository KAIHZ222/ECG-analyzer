#ifndef STANALYSIS_H
#define STANALYSIS_H

#include <ModulesInterfaces.h>


class STAnalysis : public STIntervalModule
{

public:
  virtual void runModule(const ECGRs&, const ECGWaves&, const ECGSignal&, const ECGInfo&, ECGST&);
  void setParams(ParametersTypes& );
  
  virtual ~STAnalysis();
  
private:
  class AbstractAnalizator {
  public:
    virtual ECGST::Interval analyse(const int it, const ECGRs& rpeaks, const ECGWaves& waves, const ECGSignal& signal, const ECGInfo& info) = 0;
    virtual ~AbstractAnalizator() {};
  };
  
  class SimpleAnalizator: public AbstractAnalizator {
  public:
    virtual ECGST::Interval analyse(const int it, const ECGRs& rpeaks, const ECGWaves& waves, const ECGSignal& signal, const ECGInfo& info);
  };
  
  AbstractAnalizator * analizator;
  void setAnalizator(STAnalysis::AbstractAnalizator* a = NULL);
  
  IntSignal read_normal_r_peaks(char * filename);
};

#endif // STANALYSIS_H