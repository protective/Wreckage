
#include "ProgramPrinter.h"

using namespace wkl;

string wkl::toHex(uint32_t hex, uint32_t pad){
    stringstream out;
    out<< std::showbase // show the 0x prefix
       << std::internal // fill between the prefix and the number
       << std::setfill('0'); // fill with 0s
    out << std::hex<< std::uppercase << std::setw(pad) << hex;
    return out.str();
}
string wkl::tabPad(string topad, uint32_t len){
    stringstream tab;
    tab<<"";
	if(topad.size() > len)
		return topad;
	for(; len - topad.size() > 1; len-=1)
        tab<<" ";
    return tab.str();
}
void wkl::printProgram(ostream& out, PROGRAM& p, map<uint32_t, uint32_t> interruptshandlers){
    uint32_t line = 0;
    out<<"no instruction ="<<p.size()<<endl;
	out<<endl;
	out<<"function"<<tabPad("function", 25)<<"line"<<endl;
	for (map<uint32_t, uint32_t>::iterator it = interruptshandlers.begin(); it!= interruptshandlers.end(); it++){
		
		for(auto& it2 : systemCallBackLib::lib){
			if (it2.first == it->first){
				out<<it2.second<<tabPad(it2.second,25)<<it->second<<endl;
				break;
			}
		}
	}
	out<<endl;
	/*
	out<<"envVars"<<tabPad("envVars", 20)<<"line"<<endl;
	for (map<uint32_t, uint32_t>::iterator it = interruptshandlers.begin(); it!= interruptshandlers.end(); it++){
		for(int i = 0; wkl::systemEnvLib[i]._id; i++){
			if (wkl::systemEnvLib[i]._id == it->first);
				out<<wkl::systemEnvLib[i]._name<<tabPad(wkl::systemEnvLib[i]._name,20)<<it->second<<endl;
		}	
	}
	*/
	out<<endl;
    out<<"line\topcode\t\t\targ\t"<<endl;
    for (line = 0 ; line < p.size(); ){
        uint32_t instruction = p.at(line);
        string name ="";
        bool haveArg = false;
        uint32_t noParams = 0;
        string param[5] = "";
        bool lineAddr[5] = {false};
        switch((instruction & 0xFFFF0000)){
			case inst::NOP:
            {
                name = "...NOP...";
                haveArg = false;
                break;
            }
			case inst::FUN:
            {
                name = "...FUN...";
                haveArg = true;
                break;
            }
			case inst::EOP:
            {
                name = "...EOP...";
                haveArg = false;
                break;
            }
            case inst::pushN:
            {
                name = "pushN";
                haveArg = true;
                break;
            }
			case inst::pushS0N:
            {
                name = "pushS0N";
                haveArg = true;
                break;
            }
            case inst::pushN_1:
            {
                name = "pushN_1";
                haveArg = true;
                noParams = 1;
                param[0] = "value";
                break;
            }
            case inst::popN:
            {
                name = "popN";
                haveArg = true;
                break;
            }
            case inst::cpN_ADAS2:
            {
                name = "cpN_ADAS2";
                haveArg = false;
                noParams = 2;
                param[0] = "Abs src"; 
                param[1] = "Abs dest"; 
                break;
            }
            case inst::cpN_ADRS2:
            {
                name = "cpN_ADRS2";
                haveArg = false;
                noParams = 2;
                param[0] = "Abs src"; 
                param[1] = "Rel dest"; 
                break;
            }
            case inst::cpN_RDAS2:
            {
                name = "cpN_RDAS2";
                haveArg = false;
                noParams = 2;
                param[0] = "Rel src"; 
                param[1] = "Abs dest"; 
                break;
            }
            case inst::cpN_RDRS2:
            {
                name = "cpN_RDRS2";
                haveArg = false;
                noParams = 2;
                param[0] = "Rel src"; 
                param[1] = "Rel dest"; 
                break;
            }
			
            case inst::cpN_EAD2:
            {
                name = "cpN_EAD2";
                haveArg = false;
                noParams = 2;
                param[0] = "Env src"; 
                param[1] = "Abs dest"; 
                break;
            }
            case inst::cpN_ERD2:
            {
                name = "cpN_ERD2";
                haveArg = false;
                noParams = 2;
                param[0] = "Env src"; 
                param[1] = "Rel dest"; 
                break;
            }
            case inst::cpN_AED2:
            {
                name = "cpN_AED2";
                haveArg = false;
                noParams = 2;
                param[0] = "Abs src"; 
                param[1] = "Env dest"; 
                break;
            }
            case inst::cpN_RED2:
            {
                name = "cpN_RED2";
                haveArg = false;
                noParams = 2;
                param[0] = "Rel src"; 
                param[1] = "Env dest"; 
                break;
            }
			
			
			
            case inst::cp_ASIAD2:
            {
                name = "cp_ASIAD2";
                haveArg = false;
                noParams = 3;
                param[0] = "Abs src"; 
				param[1] = "Rel index"; 
                param[2] = "Abs dest"; 
                break;
            }
            case inst::cp_ASIRD2:
            {
                name = "cp_ASIRD2";
                haveArg = false;
                noParams = 3;
                param[0] = "Abs src";
				param[1] = "Rel index"; 
                param[2] = "Rel dest"; 
                break;
            }
            case inst::cp_RSIAD2:
            {
                name = "cp_RSIAD2";
                haveArg = false;
                noParams = 3;
                param[0] = "Rel src"; 
				param[1] = "Rel index"; 
                param[2] = "Abs dest"; 
                break;
            }
            case inst::cp_RSIRD2:
            {
                name = "cp_RSIRD2";
                haveArg = false;
                noParams = 3;
                param[0] = "Rel src";
				param[1] = "Rel index";  
                param[2] = "Rel dest"; 
                break;
            }

            case inst::cp_ASsvIAD2:
            {
                name = "cp_ASsvIAD2";
                haveArg = false;
                noParams = 3;
                param[0] = "Abs src"; 
				param[1] = "Rel *index"; 
                param[2] = "Abs dest"; 
                break;
            }
            case inst::cp_ASsvIRD2:
            {
                name = "cp_ASsvIRD2";
                haveArg = false;
                noParams = 3;
                param[0] = "Abs src";
				param[1] = "Rel *index"; 
                param[2] = "Rel dest"; 
                break;
            }
            case inst::cp_RSsvIAD2:
            {
                name = "cp_RSsvIAD2";
                haveArg = false;
                noParams = 3;
                param[0] = "Rel src"; 
				param[1] = "Rel *index"; 
                param[2] = "Abs dest"; 
                break;
            }
            case inst::cp_RSsvIRD2:
            {
                name = "cp_RSsvIRD2";
                haveArg = false;
                noParams = 3;
                param[0] = "Rel src";
				param[1] = "Rel *index";  
                param[2] = "Rel dest"; 
                break;
            }
			
			
			case inst::cpCO_DS2:
            {
                name = "cpCO_DS2";
                haveArg = true;
                noParams = 2;
                param[0] = "Rel dest"; 
                param[1] = "Con src"; 
                break;
            }	
			case inst::cpEI_DS2:
            {
                name = "cpEI_DS2";
                haveArg = true;
                noParams = 2;
                param[0] = "Rel dest"; 
                param[1] = "Env src"; 
                break;
            }
			case inst::mvMapAL:
            {
                name = "mvMapAL";
                haveArg = true;
                noParams = 0;
                break;
            }
            case inst::cpI_RDS2:
            {
                name = "cpI_RDS2";
                haveArg = true;
                noParams = 2;
                param[0] = "Rel dest"; 
                param[1] = "Abs src"; 
                break;
            }
	
			case inst::cpAIS2_T:
            {
                name = "cpAIS2_T";
                haveArg = true;
                noParams = 1;
                param[0] = "Abs src"; 
                break;
            }
            case inst::cpEIS2_T:
            {
                name = "cpEIS2_T";
                haveArg = true;
                noParams = 1;
                param[0] = "Env src"; 
                break;
            }						
			case inst::jmpA_1:
            {
                name = "jmpA_1";
                haveArg = true;
                noParams = 1;
                param[0] = "Line"; 
				lineAddr[0] = true;
                break;
            }
 			case inst::cjmpA_1:
            {
                name = "cjmpA_1";
                haveArg = true;
                noParams = 1;
                param[0] = "Line";
				lineAddr[0] = true;
                break;
            }
 			case inst::cjmp2NeqA_1:
            {
                name = "cjmp2NeqA_1";
                haveArg = false;
                noParams = 1;
                param[0] = "Line";
				lineAddr[0] = true;
                break;
            }
 			case inst::addS01:
            {
                name = "addS01";
                break;
            }
 			case inst::minusS01:
            {
                name = "minusS01";
                break;
            }
 			case inst::addS01dS1:
            {
                name = "addS01dS1";
                break;
            }
 			case inst::minusS01dS1:
            {
                name = "minusS01dS1";
                break;
            }
 			case inst::eqS01dS1:
            {
                name = "eqS01dS1";
                break;
            }
 			case inst::neqS01dS1:
            {
                name = "neqS01dS1";
                break;
            }
 			case inst::sysCall:
            {
				haveArg = true;
                name = "sysCall";
				noParams = 1;
                param[0] = "Stack";

                break;
            }
 			case inst::pushPC:
            {
                name = "pushPC";
                break;
            }
 			case inst::pushRPC:
            {
                name = "pushRPC";
				noParams = 1;
                param[0] = "Line";
				lineAddr[0] = true;
                break;
            }
 			case inst::popPC:
            {
                name = "popPC";
                break;
            }
 			case inst::pushUIndx:
            {
                name = "pushUIndx";
				haveArg = false;
                noParams = 1;
                param[0] = "Rel src";
                break;
            }			
			default:{
				name = "unknown";
						break;
			}

        }
        out<<toHex(line,6)<<"\t"<<toHex(instruction>>16,4)<<" ("<<name<<")";
        if(haveArg)
            out<<"\t"<<toHex(instruction & 0x0000FFFF,4);
        out<<endl;
        for(int i = 0 ; i < noParams; i++){

            out<<toHex(line+i+1,6)<<"\t\t  "<<"\t("<<param[i]<<")"<<tabPad(param[i], 14)<<toHex(p.at(line+i+1),lineAddr[i]? 6 :  10)<<endl;
        }
        
        
        line+= 1 + noParams;           
    }
    out<<endl;
}
