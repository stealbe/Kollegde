#pragma once
#include "GroundVeh.h"

class Train : public GroundVeh
{
	protected:
	string trainType;
	int carriageCount;
	double trackGauge;
	string operatorName;
	double length;
	double maxLoad;
public:
	Train() : trainType(""), carriageCount(0), trackGauge(0.0), operatorName(""), length(0.0), maxLoad(0.0) {}
	Train(const string& t, int y, int ms, double w, int c, int wc, int hp, int dc, const string& tt, const string& ft, const string& ct, const string& trt, int cc, double tg, const string& on, double l, double ml)
		: GroundVeh(t, y, ms, w, c, wc, hp, dc, tt, ft, ct),
		trainType(trt), carriageCount(cc), trackGauge(tg), operatorName(on), length(l), maxLoad(ml) {
	}
	void setTrainType(const string& tt) { trainType = tt; }
	void setCarriageCount(int cc) { carriageCount = cc; }
	void setTrackGauge(double tg) { trackGauge = tg; }
	void setOperatorName(const string& on) { operatorName = on; }
	void setLength(double l) { length = l; }
	void setMaxLoad(double ml) { maxLoad = ml; }
	void Print() override
	{
		GroundVeh::Print();
		cout << "Train Type: " << trainType << endl;
		cout << "Carriage Count: " << carriageCount << endl;
		cout << "Track Gauge: " << trackGauge << " meters" << endl;
		cout << "Operator Name: " << operatorName << endl;
		cout << "Length: " << length << " meters" << endl;
		cout << "Max Load: " << maxLoad << " tons" << endl;
	}
	void Init(string t, int y, int ms, double w, int c,
		int wc, int hp, int dc, string tt, string ft, string ct,
		string trt, int cc, double tg, string on, double l, double ml)
	{
		GroundVeh::Init(t, y, ms, w, c,
			wc, hp, dc, tt, ft, ct);
		trainType = trt;
		carriageCount = cc;
		trackGauge = tg;
		operatorName = on;
		length = l;
		maxLoad = ml;
	}
};