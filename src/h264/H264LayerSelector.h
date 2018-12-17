#ifndef H264LAYERSELECTOR_H
#define H264LAYERSELECTOR_H

#include "config.h"
#include "VideoLayerSelector.h"
#include "h264.h"

class H264LayerSelector : public VideoLayerSelector 
{
public:
	H264LayerSelector();
	virtual ~H264LayerSelector() = default;
	
	void SelectTemporalLayer(BYTE id)		override {};
	void SelectSpatialLayer(BYTE id)		override {};
	
	bool Select(const RTPPacket::shared& packet,bool &mark)	override;
	
	BYTE GetTemporalLayer()		const override { return LayerInfo::MaxLayerId;;	}
	BYTE GetSpatialLayer()		const override { return LayerInfo::MaxLayerId;	}
	VideoCodec::Type GetCodec()	const override { return VideoCodec::H264;	}
	
	const H264SeqParameterSet&	GetSeqParameterSet()		const { return sps; }
	const H264PictureParameterSet&	GetPictureParameterSet()	const { return pps; }
	
	static LayerInfo GetLayerIds(const RTPPacket::shared& packet)	{ return LayerInfo(); }
private:
	bool waitingForIntra;
	H264SeqParameterSet sps;
	H264PictureParameterSet pps;
private:

};

#endif /* H264LAYERSELECTOR_H */

