/******************************************************************************
** xmldocument.h
**
** Copyright (c) 2006-2016 Unified Automation GmbH. All rights reserved.
**
** Software License Agreement ("SLA") Version 2.5
**
** Unless explicitly acquired and licensed from Licensor under another
** license, the contents of this file are subject to the Software License
** Agreement ("SLA") Version 2.5, or subsequent versions
** as allowed by the SLA, and You may not copy or use this file in either
** source code or executable form, except in compliance with the terms and
** conditions of the SLA.
**
** All software distributed under the SLA is provided strictly on an
** "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
** AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
** LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
** PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific
** language governing rights and limitations under the SLA.
**
** The complete license agreement can be found here:
** http://unifiedautomation.com/License/SLA/2.5/
**
** Project: C++ OPC SDK XML parser module
**
******************************************************************************/
#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H

#define XML_Document void*
#define XML_Node void*
#define XML_Attribute void*

#include "opcua_xml_parser.h"
#include "uabase.h"
#include <list>

class XML_PARSER_EXPORT UaXmlValue;

class UaByteString;

class XML_PARSER_EXPORT UaXmlAttribute
{
    UaXmlAttribute& operator=(const UaXmlAttribute&);
public:
    UaXmlAttribute();
    UaXmlAttribute(const UaXmlAttribute &other);
    ~UaXmlAttribute();

    void setAttribute(XML_Attribute newXmlAttribute);
    const char* getName() const;
    const char* getValue() const;

private:
    XML_Attribute m_xmlAttribute;
};

/** @ingroup CppXmlLibraryClass
 *
 * XML Element class.
 */
class XML_PARSER_EXPORT UaXmlElement
{
public:
    UaXmlElement();
    UaXmlElement(const UaXmlElement &other);
    ~UaXmlElement();

    UaXmlElement& operator=(const UaXmlElement &other);

    void setNode(XML_Node xmlNodeNew);

    int getRootNode();
    int getFirstChild();
    int getChild(const char* pchName);
    int getNextSibling();
    int getParentNode();
    const char* getNodeName();
    void getCurrentElement(UaXmlElement& uaXmlElement);
    int getChildElements(const char* pchName, std::list<UaXmlElement>& uaXmlElementList);
    void getContent(UaXmlValue& value);
    void getAttributeValue(const char* pchAttributeName, UaXmlValue& value);
    int setContent(char* pchSimpleContent);
private:
    // Root node of current DOM
    XML_Node     m_xmlNodeRoot;
    // Current node of current DOM
    XML_Node     m_xmlNodeWork;
};

/** @ingroup CppXmlLibraryClass
 *
 * XML Element List.
 */
typedef std::list<UaXmlElement> UaXmlElementList;

/** @ingroup CppXmlLibraryClass
 *
 * XML Element List Iterator.
 */
typedef std::list<UaXmlElement>::iterator UaXmlElementListIterator;

typedef std::list<UaXmlAttribute> UaXmlAttributeList;
typedef std::list<UaXmlAttribute>::iterator UaXmlAttributeListIterator;

/** @ingroup CppXmlLibraryClass
 *
 * XML parser class for an XML document.
 *
 * This class can be used to read or to create an XML file. The file is parsed and the content is
 * temporarily stored in a Document Object Model (DOM). The class provides methods to navigate
 * through the DOM and to read and write content to the DOM.
 *
 * <b>Note on usage:</b><br/>
 * - Call UaXmlDocument::initParser() once before calling any other method of this class.
 * - Call UaXmlDocument::cleanupParser() once to clean up resources when the UaXmlDocument
 *   class is no longer used.
 * - Call initParser only <b>once</b> on start-up (or only from the main thread) and cleanupParser
 *   <b>once</b> on exit.
 * Calling initParser multiple times from different threads will cause a memory leak.
 *
 * See \ref L3TutorialServerHelloWorld_3 "Tutorial Server Hello World" and \ref gsl01st02_02
 * "Getting Started Lesson 1" for example code.
 */
class XML_PARSER_EXPORT UaXmlDocument
{
    UaXmlDocument& operator=(const UaXmlDocument&);
public:
    static void initParser();
    static void cleanupParser();

    UaXmlDocument();
    UaXmlDocument(const char* strFilePath);
    UaXmlDocument(const UaXmlDocument &other);
    ~UaXmlDocument();

    int loadXmlFile(const char* strFilePath);
    int loadXmlText(const char* strText, int size, const char* url);
    int create(const char* pchRootNode, const char* pchSimpleContent);
    int freeXmlDocument();
    int saveXmlFile(const char* strFilePath);
    int dumpXmlFile(char** pszContent, int &rSize);
    int dumpCurrentNode(char** pszContent, int &rSize);
    int getRootNode();
    int getFirstChild();
    int getChild(const char* pchName);
    int getNextSibling();
    int getParentNode();
    const char* getNodeName();
    void getCurrentElement(UaXmlElement& uaXmlElement);
    void deleteCurrentElement();
    int getChildElements(const char* pchName, UaXmlElementList& uaXmlElementList);
    void getContent(UaXmlValue& value);
    void getAttributeValue(const char* pchAttributeName, UaXmlValue& value);
    void getAttributes(UaXmlAttributeList& uaXmlAttributeList);
    int setContent(const char* pchSimpleContent);
    int addChild(const char* pchName, const char* pchSimpleContent);
    int addAttribute(const char* pchName, const char* pchValue);
    int setAttribute(const char* pchName, const char* pchValue);
    const char* getNamespace() const;
    const char* getNamespace(const char *strNamespacePrefix) const;
    const char* getLastXmlErrorString() const;
    int getLastXmlErrorLine() const;
    int setNamespace(const char* strNamespace, const char *strNamespacePrefix = OpcUa_Null);
private:
    // Currently loaded DOM
    XML_Document m_xmlDocument;
    // Root node of current DOM
    XML_Node     m_xmlNodeRoot;
    // Current node of current DOM
    XML_Node     m_xmlNodeWork;
};


/** @ingroup CppXmlLibraryClass
 *
 * XML Value class.
 */
class XML_PARSER_EXPORT UaXmlValue
{
    UA_DISABLE_COPY(UaXmlValue);
public:
    UaXmlValue();
    UaXmlValue(char* strValue);
    ~UaXmlValue();

    void clear();
    void setValue(char* strValue);

    inline const char* pValue() { return m_strValue;};

private:
    char* m_strValue;
};


#endif //XMLDOCUMENT_H

