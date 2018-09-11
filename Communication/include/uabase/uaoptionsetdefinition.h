#ifndef UAOPTIONSETDEFINITION_H
#define UAOPTIONSETDEFINITION_H

#include "uadatatypedefinition.h"
#include "uaabstractdefinition.h"
#include "ualocalizedtext.h"
#include "uaarraytemplates.h"

class UABASE_EXPORT UaOptionSetDefinitionPrivate;

/** The class describes an OptionSet.
 *
 * You can access the values by index..
 *
 */
class UABASE_EXPORT UaOptionSetDefinition : public UaAbstractDefinition
{
public:
    UaOptionSetDefinition();
    UaOptionSetDefinition(const UaOptionSetDefinition &other);

    enum BaseType
    {
        BaseType_Byte,
        BaseType_UInt16,
        BaseType_UInt32,
        BaseType_UInt64,
        BaseType_OptionSet
    };

    UaOptionSetDefinition& operator=(const UaOptionSetDefinition &other);

    bool operator==(const UaOptionSetDefinition &other) const;
    bool operator!=(const UaOptionSetDefinition &other) const;

    // UaAbstractDefinition interface
public:
    virtual void clear();
    virtual void setDataTypeId(const UaNodeId &nodeId);
    virtual void setName(const UaString &sName);
    virtual void setDocumentation(const UaLocalizedText &documentation);
    virtual void setNamespace(const UaString &sNamespace);
    virtual int childrenCount() const;

    BaseType baseType() const;
    void setBaseType(BaseType baseType);
    UaLocalizedText child(int i) const;
    void addChild(const UaLocalizedText &newChild);
    UaLocalizedTextArray children() const;
    void setChildren(const UaLocalizedTextArray &children);
    bool hasValidBits() const;

    void setBinaryEncodingId(const UaNodeId &nodeId);
    UaNodeId binaryEncodingId() const;
    void setXmlEncodingId(const UaNodeId &nodeId);
    UaNodeId xmlEncodingId() const;

    UaStructureDefinition structureDefinition() const;
};

#endif
