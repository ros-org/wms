#ifndef UAENCODERTYPE_H
#define UAENCODERTYPE_H

#include <opcua_encoder.h>

enum UaEncoderType
{
    Encoder_Binary = OpcUa_EncoderType_Binary
#ifdef HAVE_XML_ENCODER
    , Encoder_Xml = OpcUa_EncoderType_Xml
#endif
};

#endif //UAENCODERTYPE_H
