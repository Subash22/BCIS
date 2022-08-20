#include<stdio.h>
#include<winsock2.h>
#include<string.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *message , server_reply[200];
    int recv_size;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
	if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	
	// puts("Bind done");

    puts("Connected");

    // Work well with Get Method
    // strcat(message, "GET /voleur/receiver.php?arg1=Hello HTTP/1.1\n");
    // strcat(message, "POST /voleur/receiver.php HTTP/1.1\n");
    // strcat(message, "Host: 127.0.0.1\n");
    // strcat(message, "Connection: close\n");
    // strcat(message, "Content-Type: application/octet-stream\n");
    // strcat(message, "Content-Encoding: binary\n");
    // strcat(message, "Content-Length: 16\n");
    // strcat(message, "Accept-Charset: utf-8\n\n");
    strcat(message, "POST /tmsapi/orderApi/orderbook-v2/ HTTP/1.1\n");
    strcat(message, "Host: tms42.nepsetms.com.np\n");
    strcat(message, "Accept: application/json, text/plain, */*\n");
    strcat(message, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:87.0) Gecko/20100101 Firefox/87.0\n");
    strcat(message, "Accept-Language: en-GB,en;q=0.5\n");
    strcat(message, "Accept-Encoding: gzip, deflate, br\n");
    strcat(message, "X-XSRF-TOKEN: adb5e7ec-5726-427c-a0c0-c5bfe078cdfb\n");
    strcat(message, "Content-Type: application/json\n");
    strcat(message, "Content-Length: 3829\n");
    strcat(message, "Origin: https://tms42.nepsetms.com.np\n");
    strcat(message, "Connection: keep-alive\n");
    strcat(message, "Referer: https://tms42.nepsetms.com.np/tms/me/memberclientorderentry\n");
    strcat(message, "Cookie: refreshToken=eyJhbGciOiJIUzI1NiJ9.eyJqdGkiOiIxNjAwMTUiLCJpYXQiOjE2MTY1NjcyMjAsInN1YiI6Ik1BRC1VQ1IsTUlORk8tUixGTS1BMURVQ0EyUkEzLE9NLVVDUixTQkktQTFEVUNBMlJBMyxMRi1BMURVQ0EyUkEzLEdMLVIsVEItVUNSLFNRLVIsTVctUixQRi1BMURVQ0EyUkEzLE1XREMtUixPQi1BMURVQ0EyUkEzLERILVVDUixDQ00tQTFEVUNBMlJBMyxPQkgtUixDUy1BMURVQ0EyUkEzLFRSLVVDUixTU0ktQTFEVUNBMlJBMyxDRlQtQTFEVUNBMlJBMyxGVy1BMURVQ0EyUkEzLFNUTEJJLVVDUixXUy1SLE1MTldTLVIsTUwtUixETkFTLVIsQ0xUUy1SLE1DT0UtQTFEVUNBMlJBMyxETkFMLVIsVEJILVIiLCJpc3MiOiIyMDIwMDk2NTUzIiwiZXhwIjoxNjE2NTY3NTIwLCJpc0NsaWVudCI6IjEiLCJpc01lbWJlciI6IjAiLCJpc0RlYWxlciI6IjAifQ.sBC23ncdbVohW9jO2gdSiHeMrNjySCzaxbs63TkFaIw; accessToken=eyJhbGciOiJIUzI1NiJ9.eyJqdGkiOiIxNjAwMTUiLCJpYXQiOjE2MTY1NjcyMjAsInN1YiI6Ik1BRC1VQ1IsTUlORk8tUixGTS1BMURVQ0EyUkEzLE9NLVVDUixTQkktQTFEVUNBMlJBMyxMRi1BMURVQ0EyUkEzLEdMLVIsVEItVUNSLFNRLVIsTVctUixQRi1BMURVQ0EyUkEzLE1XREMtUixPQi1BMURVQ0EyUkEzLERILVVDUixDQ00tQTFEVUNBMlJBMyxPQkgtUixDUy1BMURVQ0EyUkEzLFRSLVVDUixTU0ktQTFEVUNBMlJBMyxDRlQtQTFEVUNBMlJBMyxGVy1BMURVQ0EyUkEzLFNUTEJJLVVDUixXUy1SLE1MTldTLVIsTUwtUixETkFTLVIsQ0xUUy1SLE1DT0UtQTFEVUNBMlJBMyxETkFMLVIsVEJILVIiLCJpc3MiOiIyMDIwMDk2NTUzIiwiZXhwIjoxNjE2NTk3MjIwLCJpc0NsaWVudCI6IjEiLCJpc01lbWJlciI6IjAiLCJpc0RlYWxlciI6IjAifQ.DJ8-By9miVmb_oBK2btyG9-1qaXueX2itpQ39-arL-Y; XSRF-TOKEN=adb5e7ec-5726-427c-a0c0-c5bfe078cdfb\n");

    puts("header included");

    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    // My argument
    char *data = "{'orderBook':{'orderBookExtensions':[{'orderTypes':{'id':1,'orderTypeCode':'LMT'},'disclosedQuantity':0,'orderValidity':{'id':1,'orderValidityCode':'DAY'},'triggerPrice':0,'orderPrice':499,'orderQuantity':10,'remainingOrderQuantity':10,'marketType':{'id':2,'marketType':'Continuous'}}],'exchange':{'id':1},'dnaConnection':{},'dealer':{},'member':{},'productType':{'id':1,'productCode':'CNC'},'instrumentType':{'id':1,'code':'EQ'},'client':{'activeStatus':'A','id':2158327,'accountType':'CLI','allowedToTrade':'Y','clientMemberCode':'2020096553','clientOrDealer':'C','contactNumber':'9865075123','emailId':'skhatiwada225@gmail.com','notsUniqueClientCode':'202010011625738','clientDealerType':null,'clientGroup':null,'memberBranch':null,'clientDealerAddressDetails':null,'clientDealerBankDetail':{'activeStatus':'A','id':53404,'branchName':null,'accountNumber':'040000832W','accountType':{'activeStatus':'A','id':5,'code':'SAV','name':'Saving'},'parentId':null,'recordType':null,'bankBranchMaster':{'activeStatus':'A','id':4747,'bank':{'activeStatus':'A','id':103,'code':'BO103','name':'Nepal Bangladesh Bank Ltd','eBankingUrl':null,'method':null,'verificationURL':null,'redirectionUrl':null,'fileNumber':0,'nchlBankId':'0901','providerType':null,'nchlHeadBranchId':'1','bankBranchMasters':null,'isAccValidationEnabled':true,'cipsEnabled':true,'nchlBank':true,'ebankingEnabled':null},'branchId':'40','branchName':'KHAIRENI BRANCH'},'isValidated':1,'lastValidatedOn':'2021-02-04','primary':null},'clientDealerIndividual':{'activeStatus':'A','id':2158012,'annualIncome':0,'citizenshipNumber':'35017405585','dateOfBirth':'2000-08-26','fathersName':'Ram Krishna Khatiwada','firstName':'Subash','gender':'M','lastName':'Khatiwada','maritalStatus':'Unmarried','middleName':'','nationality':{'activeStatus':'A','id':82,'country':'Nepal','countryCode':'NPR','currencySymbol':'?','currency':'Rupees'},'phoneNumber1':'9865075123','grandFathersName':'Agni Prasad Khatiwada','citizenshipIssuedPlace':'Chitwan','citizenshipIssuedDate':'2017-08-04','parentId':null,'recordType':null,'mobileNo':null,'motherName':'Lom Kumari Khatiwada','spouseName':null,'sonName':null,'daughterName':null,'daughterInLawName':null,'fatherInLawName':null,'motherInLawName':null,'isMinor':false,'isNrn':false,'nrnidno':null,'photo':null,'occupation':{'activeStatus':'A','id':9,'name':'Student','category':{'activeStatus':'A','id':1,'categoryName':'Occupation'}},'businesstype':null,'organizationName':null,'organizationAddress':null,'designation':null,'employeeId':null,'financialDetails':{'activeStatus':'A','id':23,'name':'Upto 5,00,000','category':{'activeStatus':'A','id':6,'categoryName':'Financial Details'}},'isInvolvedInInvestCompany':false,'investmentCompanyName':null,'designationInInvestComp':null,'guardianName':null,'guardianRelationship':null,'guardianTelephoneNo':null,'guardianMobileNo':null,'guardianFaxNo':null,'guardianPanNo':null,'guardianEmailId':null},'clientDealerPerTradeLimits':null,'clientDealerProductMappings':null,'clientDealerOrderTypeMappings':null,'clientDealerTradingLimits':null,'clientDepositoryDetail':{'activeStatus':'A','id':53493,'depositoryAccount1':1301510000074402,'depositoryAccount2':null,'depositoryAccount3':null,'parentId':null,'recordType':null},'corporateDetail':null,'corporateOwnershipDetails':null,'displayName':'Subash Khatiwada','blockedDate':null,'remarks':'','parentId':null,'recordType':null,'collateralByEntities':null,'shortSellMode':0,'onlineOrOffline':1,'panNumber':null,'onlineFundTransfer':null,'collateralCalculationMode':1,'isMarginLendingClient':false,'clientRiskType':'Medium Risk'},'security':{'id':2876,'exchangeSecurityId':2925,'marketProtectionPercentage':0,'divisor':100,'boardLotQuantity':1,'tickSize':1},'accountType':1,'cpMemberId':0,'buyOrSell':1},'orderPlacedBy':2,'exchangeOrderId':null}";
    send(s , data , strlen(data), 0);
    puts("Data Send\n");

    //Receive a reply from the server
    if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
    }

    puts("Reply received\n");

    //Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts(server_reply);

    return 0;
}

// gcc nepse-auto.c -o nepse -lws2_32