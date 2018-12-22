// Parsed informations from IDL file compilation
//
// Copyright 2004 Bae,Hyun-jik.  All rights reserved.
//
// Permission is granted to use this code for any purpose, as long as this
// copyright message remains intact.

#pragma once

#include <antlr/refcount.hpp>

using namespace antlr;

class CSpecification;
class CConfigurations;
class CConfiguration;
class CFunction;
class CParameter;

//////////////////////////////////////////////////////////////////////////
// note that parsed information data are collected from class IDLParser.
// IDLParser is generated by compiling .g file.

/** parsed information data: IDL configuration */
class CConfiguration
{
public:
	string m_name; // Config variable name
	string m_value; // config variable value

	void SetName(string name);
	void SetValue(string value);
};

/** parsed information data: IDL configuration list */
class CConfigurations
{
public:
	string m_startID; // the first message identifier declared in IDL file.
	int m_incID; // the incremented number for each RPC function declaration.

	CConfigurations();
	void AddConfig(CConfiguration *config);
};

/** parsed information data: an RPC function declaration */
class CFunction
{
public:
	string m_ID; // message identifier assigned to this RPC function. 
	string m_name; // RPC function name

	// RPC function parameters list
	typedef vector<CParameter> Parameters; 
	Parameters m_params;

	void SetName(string name);
	void AddParameter(CParameter* param);
};

/** parsed information data: a RPC function parameter */
class CParameter
{
public:
	// parameter name and type name
	string m_name,m_type;

	void SetType(string type);
	void SetName(string name);
};


/** main of IDL parsing output */
class CSpecification
{
	// collected configuration variables 
	CConfigurations m_configurations;
public:
	// collected RPC function declarations
	typedef vector<CFunction> Functions;
	Functions m_functions;

	CSpecification(void);
	~CSpecification(void);

	void SetConfigs(CConfigurations *configs);
	void AddFunction(CFunction* func);
};

