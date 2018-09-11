/******************************************************************************
** opcua_xml_parser.h
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
#ifndef __OpcUa_Xml_Parser_H_
#define __OpcUa_Xml_Parser_H_

#define OPCUA_XML_FORMAT 1 /* 1 = format xml output; 0 = single line output */

OPCUA_BEGIN_EXTERN_C

#ifdef _WIN32
    #ifdef _XML_PARSER_BUILD_DLL
        #define XML_PARSER_EXPORT __declspec(dllexport)
    #elif defined _XML_PARSER_USE_DLL
        #define XML_PARSER_EXPORT __declspec(dllexport)
    #else
        #define XML_PARSER_EXPORT
    #endif
#else
    #define XML_PARSER_EXPORT
#endif

/**
 * @brief A handle to a xml node (element).
 */
typedef OpcUa_Handle OpcUa_XML_Node;
/**
 * @brief A handle to a xml document.
 */
typedef OpcUa_Handle OpcUa_XML_Document;
/**
 * @brief A handle to a xml namespace.
 */
typedef OpcUa_Handle OpcUa_XML_Namespace;

typedef OpcUa_Handle OpcUa_Xml_Attribute;

/* XML Management */

/**
 * @brief Initialize the xml parser. Must be called before the first use.
 */
OpcUa_Void OpcUa_XML_InitParser();

/**
 * @brief Clean up the xml parser. Must be called after the last use.
 */
OpcUa_Void OpcUa_XML_CleanUpParser();

/**
 * @brief Debug only!
 */
OpcUa_Void OpcUa_XML_Debug_MemoryDump();

/**
 * @brief Debug only!
 */
OpcUa_Int OpcUa_XML_Debug_MemoryUsed();

/**
 * @brief Free memory allocated by the xml parser to return values.
 */
XML_PARSER_EXPORT OpcUa_Void OpcUa_XML_Free(OpcUa_Void* pvMem);

/**
 * @brief Free a instantiated xml document.
 */
XML_PARSER_EXPORT OpcUa_Void OpcUa_XML_FreeDocument(OpcUa_XML_Document xmlDocument);




/* XML Dom Interface */

/**
 * @brief Retrieves a node handle to the root node of a xml document.
 */
XML_PARSER_EXPORT OpcUa_XML_Node OpcUa_XML_GetElementRoot(OpcUa_XML_Document xmlDocument);

/**
 * @brief Returns a handle to the first child element of the given xml node.
 */
XML_PARSER_EXPORT OpcUa_XML_Node OpcUa_XML_GetElementChild(OpcUa_XML_Node a_xmlNode);

/**
 * @brief  Returns a handle to the next sibling of the given xml node.
 */
XML_PARSER_EXPORT OpcUa_XML_Node OpcUa_XML_GetElementNext(OpcUa_XML_Node a_xmlNode);

/**
 * @brief  Returns a handle to the parent element of the given xml node.
 */
XML_PARSER_EXPORT OpcUa_XML_Node OpcUa_XML_GetElementParent(OpcUa_XML_Node a_xmlNode);

/**
 * @brief  Returns a handle to the previous element of the given xml node.
 */
XML_PARSER_EXPORT OpcUa_XML_Node OpcUa_XML_GetElementPrev(OpcUa_XML_Node a_xmlNode);

/**
 * @brief Returns a pointer to the element name of the given xml node.
 * Must not be freed!
 */
XML_PARSER_EXPORT const OpcUa_CharA* OpcUa_XML_GetElementName(OpcUa_XML_Node a_xmlNode);

/**
 * @brief Returns a pointer to the element content of the given xml node.
 * Must not be freed!
 */
XML_PARSER_EXPORT OpcUa_CharA* OpcUa_XML_GetElementContent(OpcUa_XML_Node a_xmlNode);

/**
 * @brief Returns a pointer to the element content of the given xml node.
 * Short Version of OpcUa_XML_GetElementContent.
 * Must not be freed!
 */
XML_PARSER_EXPORT OpcUa_CharA* OpcUa_XML_GetElementContentNA(OpcUa_XML_Node a_xmlNode);

/**
 * @brief Returns the value of a attribute identified by the node handle and the name of the attribute.
 * The returned memory must be freed with the xml free function.
 */
XML_PARSER_EXPORT OpcUa_CharA* OpcUa_XML_GetAttribute(OpcUa_XML_Node     a_xmlNode,
                                                      const OpcUa_CharA* a_strAttributeName);

/**
 * @brief Returns the value of a attribute identified by the node handle and the name of the attribute.
 * The returned memory must be freed with the xml free function.
 * Short Version of OpcUa_XML_GetAttribute.
 */
XML_PARSER_EXPORT OpcUa_CharA* OpcUa_XML_GetAttributeNA(OpcUa_XML_Node     a_xmlNode,
                                                        const OpcUa_CharA* a_strAttributeName);

XML_PARSER_EXPORT OpcUa_Xml_Attribute OpcUa_XML_GetFirstAttribute(OpcUa_XML_Node a_xmlNode);

XML_PARSER_EXPORT OpcUa_Xml_Attribute OpcUa_XML_GetNextAttribute(OpcUa_Xml_Attribute a_xmlAttribute);

XML_PARSER_EXPORT OpcUa_CharA* OpcUa_XML_GetAttributeName(OpcUa_Xml_Attribute a_xmlAttribute);

XML_PARSER_EXPORT OpcUa_CharA* OpcUa_XML_GetAttributeValue(OpcUa_Xml_Attribute a_xmlAttribute);

/**
 * @brief Creates an empty dom
 */
XML_PARSER_EXPORT OpcUa_XML_Document OpcUa_XML_CreateDocument();

XML_PARSER_EXPORT OpcUa_XML_Node OpcUa_XML_SetRootNode(OpcUa_XML_Document  a_xmlDoc,
                                                       OpcUa_XML_Namespace a_xmlNamespace,
                                                       const OpcUa_CharA*  a_strRootName,
                                                       const OpcUa_CharA*  a_strRootContent);

/**
 * @brief Writes the xml document into a string.
 * The written document must be freed with the xml free function.
 */
XML_PARSER_EXPORT OpcUa_Void OpcUa_XML_GetTextFromDocument(OpcUa_XML_Document a_xmlDoc,
                                                           OpcUa_CharA**      a_strXmlText,
                                                           OpcUa_Int*         a_intXmlTextLength);

/**
 * @brief Instantiates a DOM based on the given string.
 */
XML_PARSER_EXPORT OpcUa_XML_Document OpcUa_XML_GetDocumentFromText(const OpcUa_CharA* a_strText,
                                                                   OpcUa_Int          a_intTextSize,
                                                                   const OpcUa_CharA* a_strUrl);

/**
 * @brief Writes the given xml document into a file.
 */
XML_PARSER_EXPORT OpcUa_Int OpcUa_XML_GetFileFromDocument(const OpcUa_CharA* a_strPath,
                                                          OpcUa_XML_Document a_xmlDoc,
                                                          OpcUa_Boolean      a_bFormatOutput);

/**
 * @brief Writes the given xml document into a string.
 * The caller must free the string
 */
XML_PARSER_EXPORT OpcUa_Int OpcUa_XML_DumpDocument(OpcUa_XML_Document a_xmlDoc,
                                                   OpcUa_Boolean      a_bFormatOutput,
                                                   OpcUa_Int*         a_piSize,
                                                   OpcUa_CharA**      a_pstrContent);

/**
 * @brief Writes the given xml node into a string.
 * The caller must free the string
 */
XML_PARSER_EXPORT OpcUa_Int OpcUa_XML_DumpNode(OpcUa_XML_Document  a_xmlDoc,
                                               OpcUa_XML_Node      a_xmlNode,
                                               OpcUa_Boolean       a_bFormatOutput,
                                               OpcUa_Int*          a_piSize,
                                               OpcUa_CharA**       a_pstrContent);

/**
 * @brief Instantiates a DOM based on the given file location.
 */
XML_PARSER_EXPORT OpcUa_XML_Document OpcUa_XML_GetDocumentFromFile(const OpcUa_CharA* a_strPath);

/**
 * @brief Adds a new child element including namespace and content to the given xml node.
 */
XML_PARSER_EXPORT OpcUa_XML_Node OpcUa_XML_AddElementChild(OpcUa_XML_Node      a_xmlNodeParent,
                                                           OpcUa_XML_Namespace a_xmlNamespace,
                                                           const OpcUa_CharA*  a_strElementName,
                                                           const OpcUa_CharA*  a_strElementContent);

/**
 * @brief Deletes the node and deletes all children.
 */
XML_PARSER_EXPORT OpcUa_Void OpcUa_XML_DeleteElement(OpcUa_XML_Node a_xmlNodeToDelete);

/**
 * @brief Append the extra substring to the node content.
 */
XML_PARSER_EXPORT OpcUa_Int OpcUa_XML_AddElementContent(OpcUa_XML_Node     a_xmlNode,
                                                        const OpcUa_CharA* a_strElementContent);

/**
 * @brief Replace the content of a node.
 */
XML_PARSER_EXPORT OpcUa_Int OpcUa_XML_SetElementContent(OpcUa_XML_Node     a_xmlNode,
                                                        const OpcUa_CharA* a_strElementContent);

/**
 * @brief Append the extra substring to the node content.
 *
 * @param xmlNode                   The node to be modified.
 * @param strElementContent         The content which gets appended.
 * @param intElementContentLength   The length of the content which gets appended.
 */
XML_PARSER_EXPORT OpcUa_Void OpcUa_XML_AddElementContentWithLength(OpcUa_XML_Node     a_xmlNode,
                                                                   const OpcUa_CharA* a_strElementContent,
                                                                   OpcUa_Int          a_intElementContentLength);

/**
 * @brief Adds an attribute with the given name and value to the given xml node.
 */
XML_PARSER_EXPORT OpcUa_Int OpcUa_XML_AddAttribute(OpcUa_XML_Node     a_xmlNode,
                                                   const OpcUa_CharA* a_strAttributeName,
                                                   const OpcUa_CharA* a_strAttributeValue);

/**
 * @brief Sets the value of the attribute of the given xml node to a new value.
 */
XML_PARSER_EXPORT OpcUa_Int OpcUa_XML_SetAttribute(OpcUa_XML_Node     a_xmlNode,
                                                   const OpcUa_CharA* a_strAttributeName,
                                                   const OpcUa_CharA* a_strAttributeValue);

/**
 * @brief Sets the value of the attribute of the given xml node to a new value.
 */
XML_PARSER_EXPORT OpcUa_Void OpcUa_XML_AddAttributeWithLength(OpcUa_XML_Node     a_xmlNode,
                                                              const OpcUa_CharA* a_strAttributeName,
                                                              const OpcUa_CharA* a_strAttributeValue,
                                                              OpcUa_Int          a_intValueLength);

/** @brief Retrieve a pointer to the namespace of the given node.
  * The returned value must not be freed!
  *
  * @param xmlNode The node to retrieve the namespace uri from.
  *
  * @return The URI of the element namespace.
  */
XML_PARSER_EXPORT const OpcUa_CharA* OpcUa_XML_GetElementNamespaceURI(OpcUa_XML_Document a_xmlDocument,
                                                                      OpcUa_XML_Node     a_xmlNode);

/** @brief Search a Ns registered under a given name space for a document.
  * Recurse on the parents until it finds the defined namespace or return OpcUa_Null otherwise.
  * strNamespacePrefix can be OpcUa_Null, this is a search for the default namespace.
  *
  * @param xmlDocument        The document to search in.
  * @param xmlNode            The node to start the search from.
  * @param strNamespacePrefix The prefix of the namespace searched.
  */
XML_PARSER_EXPORT OpcUa_XML_Namespace OpcUa_XML_GetNamespace(OpcUa_XML_Document a_xmlDocument,
                                                             OpcUa_XML_Node     a_xmlNode,
                                                             const OpcUa_CharA* a_strNamespacePrefix);

XML_PARSER_EXPORT OpcUa_XML_Namespace OpcUa_XML_NewNamespace(OpcUa_XML_Node     a_xmlNode,
                                                             const OpcUa_CharA* a_strNamespace,
                                                             const OpcUa_CharA* a_strNamespacePrefix);

XML_PARSER_EXPORT const OpcUa_CharA* OpcUa_XML_GetNamespaceUri(OpcUa_XML_Namespace a_xmlNamespace);

OPCUA_END_EXTERN_C

#endif /* __OpcUa_Xml_Parser_H_ */
