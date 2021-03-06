//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef MAC16094METRICS_H_
#define MAC16094METRICS_H_

#include "../../veins/src/veins/modules/mac/ieee80211p/Mac1609_4.h"
using namespace std;
#include <Metrics.h>
#include "ChannelService.h"
class Mac16094Metrics : public Mac1609_4{
public:
    virtual ~Mac16094Metrics();
    Metrics* metrics;
    double throughputMetricMac;
    double statsMbpsReceived;
    double statsControlMbpsReceived;
    double throughputMbps;
    simsignal_t throughputSignalMac;
    double throughputControlMbps;
    double throughputMbpsSignal;
    int receivedFramesLowerMsg;
    int receivedBitsLowerPackets;
    int receivedBitsLowerWsm;
    int packetsNotForMe;
    double statsReceivedBits;
    double collisionsPktNonDecoded;
    std::map<int,simtime_t> channelUtilization;
    std::map<int, double> previousSignalQuality;
    std::map<int, double> channelPacketsTransmitted;
    std::array<int, 200> neighbors;
    int numberOfNeighbors;
    std::map<int, double> channelQuality;
    ChannelService* channelService;

protected:
    void computeThroughput(Metrics*, double, double);
    void computeThroughputMbps(Metrics*, double, double, double);

    virtual void initialize(int);
    virtual void finish();
    virtual void handleLowerMsg(cMessage*);
    virtual void handleUpperMsg(cMessage*);
    virtual void handleSelfMsg(cMessage*);
    virtual void handleLowerControl(cMessage* msg);
    virtual void handleUpperControl(cMessage* msg);
    double getCollisionsPktNotDecoded();
    double getThroughputMetricMac();
    double getThroughputMbps();

    int randomizeSCH( int min, int max);

private:
    void recordChannelUtilized(const omnetpp::simtime_t& sendingDuration);
    void recordSignalQuality(double txPower);
    void recordChannelPackets(int chan);
    void recordNeighbors(int senderId, long receiverAddr);
    void recordScalarNeighbors();
};

#endif /* MAC16094METRICS_H_ */
