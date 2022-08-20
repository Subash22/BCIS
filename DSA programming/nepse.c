#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char *argv[]){
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_URL, "https://tms42.nepsetms.com.np/tmsapi/orderApi/orderbook-v2/");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Host:  tms42.nepsetms.com.np");
    headers = curl_slist_append(headers, "User-Agent:  Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:88.0) Gecko/20100101 Firefox/88.0");
    headers = curl_slist_append(headers, "Accept:  application/json, text/plain, */*");
    headers = curl_slist_append(headers, "Accept-Language:  en-GB,en;q=0.5");
    headers = curl_slist_append(headers, "Accept-Encoding:  gzip, deflate, br");
    headers = curl_slist_append(headers, "X-XSRF-TOKEN:  baad4cb7-4855-41fd-8fdf-9bce793b81c5");
    headers = curl_slist_append(headers, "Content-Type:  application/json");
    headers = curl_slist_append(headers, "Content-Length:  3829");
    headers = curl_slist_append(headers, "Origin:  https://tms42.nepsetms.com.np");
    headers = curl_slist_append(headers, "Connection:  keep-alive");
    headers = curl_slist_append(headers, "Referer:  https://tms42.nepsetms.com.np/tms/me/memberclientorderentry");
    headers = curl_slist_append(headers, "Cookie:  refreshToken=eyJhbGciOiJIUzI1NiJ9.eyJqdGkiOiIxNjAwMTUiLCJpYXQiOjE2MTY1NzU0MDgsInN1YiI6Ik1BRC1VUkMsTUlORk8tUixGTS1BM0EyRFVSQ0ExLE9NLVVSQyxTQkktQTNBMkRVUkNBMSxMRi1BM0EyRFVSQ0ExLEdMLVIsVEItVVJDLFNRLVIsTVctUixQRi1BM0EyRFVSQ0ExLE1XREMtUixPQi1BM0EyRFVSQ0ExLERILVVSQyxDQ00tQTNBMkRVUkNBMSxPQkgtUixDUy1BM0EyRFVSQ0ExLFRSLVVSQyxTU0ktQTNBMkRVUkNBMSxDRlQtQTNBMkRVUkNBMSxGVy1BM0EyRFVSQ0ExLFNUTEJJLVVSQyxXUy1SLE1MTldTLVIsTUwtUixETkFTLVIsQ0xUUy1SLE1DT0UtQTNBMkRVUkNBMSxETkFMLVIsVEJILVIiLCJpc3MiOiIyMDIwMDk2NTUzIiwiZXhwIjoxNjE2NTc1NzA4LCJpc0NsaWVudCI6IjEiLCJpc01lbWJlciI6IjAiLCJpc0RlYWxlciI6IjAifQ.2nx-qiBVE5nD3NIHPG-JoTAW_xF3rXNqUI_VqOGjKI4; accessToken=eyJhbGciOiJIUzI1NiJ9.eyJqdGkiOiIxNjAwMTUiLCJpYXQiOjE2MTY1NzU0MDgsInN1YiI6Ik1BRC1VUkMsTUlORk8tUixGTS1BM0EyRFVSQ0ExLE9NLVVSQyxTQkktQTNBMkRVUkNBMSxMRi1BM0EyRFVSQ0ExLEdMLVIsVEItVVJDLFNRLVIsTVctUixQRi1BM0EyRFVSQ0ExLE1XREMtUixPQi1BM0EyRFVSQ0ExLERILVVSQyxDQ00tQTNBMkRVUkNBMSxPQkgtUixDUy1BM0EyRFVSQ0ExLFRSLVVSQyxTU0ktQTNBMkRVUkNBMSxDRlQtQTNBMkRVUkNBMSxGVy1BM0EyRFVSQ0ExLFNUTEJJLVVSQyxXUy1SLE1MTldTLVIsTUwtUixETkFTLVIsQ0xUUy1SLE1DT0UtQTNBMkRVUkNBMSxETkFMLVIsVEJILVIiLCJpc3MiOiIyMDIwMDk2NTUzIiwiZXhwIjoxNjE2NjA1NDA4LCJpc0NsaWVudCI6IjEiLCJpc01lbWJlciI6IjAiLCJpc0RlYWxlciI6IjAifQ.UFA-FskyabhN2hdhHYfBugi2zqEYPn8s1vhOfpFC27Q; XSRF-TOKEN=baad4cb7-4855-41fd-8fdf-9bce793b81c5");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    const char *data = "{\"orderBook\":{\"orderBookExtensions\":[{\"orderTypes\":{\"id\":1,\"orderTypeCode\":\"LMT\"},\"disclosedQuantity\":0,\"orderValidity\":{\"id\":1,\"orderValidityCode\":\"DAY\"},\"triggerPrice\":0,\"orderPrice\":499,\"orderQuantity\":10,\"remainingOrderQuantity\":10,\"marketType\":{\"id\":2,\"marketType\":\"Continuous\"}}],\"exchange\":{\"id\":1},\"dnaConnection\":{},\"dealer\":{},\"member\":{},\"productType\":{\"id\":1,\"productCode\":\"CNC\"},\"instrumentType\":{\"id\":1,\"code\":\"EQ\"},\"client\":{\"activeStatus\":\"A\",\"id\":2158327,\"accountType\":\"CLI\",\"allowedToTrade\":\"Y\",\"clientMemberCode\":\"2020096553\",\"clientOrDealer\":\"C\",\"contactNumber\":\"9865075123\",\"emailId\":\"skhatiwada225@gmail.com\",\"notsUniqueClientCode\":\"202010011625738\",\"clientDealerType\":null,\"clientGroup\":null,\"memberBranch\":null,\"clientDealerAddressDetails\":null,\"clientDealerBankDetail\":{\"activeStatus\":\"A\",\"id\":53404,\"branchName\":null,\"accountNumber\":\"040000832W\",\"accountType\":{\"activeStatus\":\"A\",\"id\":5,\"code\":\"SAV\",\"name\":\"Saving\"},\"parentId\":null,\"recordType\":null,\"bankBranchMaster\":{\"activeStatus\":\"A\",\"id\":4747,\"bank\":{\"activeStatus\":\"A\",\"id\":103,\"code\":\"BO103\",\"name\":\"Nepal Bangladesh Bank Ltd\",\"eBankingUrl\":null,\"method\":null,\"verificationURL\":null,\"redirectionUrl\":null,\"fileNumber\":0,\"nchlBankId\":\"0901\",\"providerType\":null,\"nchlHeadBranchId\":\"1\",\"bankBranchMasters\":null,\"isAccValidationEnabled\":true,\"cipsEnabled\":true,\"nchlBank\":true,\"ebankingEnabled\":null},\"branchId\":\"40\",\"branchName\":\"KHAIRENI BRANCH\"},\"isValidated\":1,\"lastValidatedOn\":\"2021-02-04\",\"primary\":null},\"clientDealerIndividual\":{\"activeStatus\":\"A\",\"id\":2158012,\"annualIncome\":0,\"citizenshipNumber\":\"35017405585\",\"dateOfBirth\":\"2000-08-26\",\"fathersName\":\"Ram Krishna Khatiwada\",\"firstName\":\"Subash\",\"gender\":\"M\",\"lastName\":\"Khatiwada\",\"maritalStatus\":\"Unmarried\",\"middleName\":\"\",\"nationality\":{\"activeStatus\":\"A\",\"id\":82,\"country\":\"Nepal\",\"countryCode\":\"NPR\",\"currencySymbol\":\"?\",\"currency\":\"Rupees\"},\"phoneNumber1\":\"9865075123\",\"grandFathersName\":\"Agni Prasad Khatiwada\",\"citizenshipIssuedPlace\":\"Chitwan\",\"citizenshipIssuedDate\":\"2017-08-04\",\"parentId\":null,\"recordType\":null,\"mobileNo\":null,\"motherName\":\"Lom Kumari Khatiwada\",\"spouseName\":null,\"sonName\":null,\"daughterName\":null,\"daughterInLawName\":null,\"fatherInLawName\":null,\"motherInLawName\":null,\"isMinor\":false,\"isNrn\":false,\"nrnidno\":null,\"photo\":null,\"occupation\":{\"activeStatus\":\"A\",\"id\":9,\"name\":\"Student\",\"category\":{\"activeStatus\":\"A\",\"id\":1,\"categoryName\":\"Occupation\"}},\"businesstype\":null,\"organizationName\":null,\"organizationAddress\":null,\"designation\":null,\"employeeId\":null,\"financialDetails\":{\"activeStatus\":\"A\",\"id\":23,\"name\":\"Upto 5,00,000\",\"category\":{\"activeStatus\":\"A\",\"id\":6,\"categoryName\":\"Financial Details\"}},\"isInvolvedInInvestCompany\":false,\"investmentCompanyName\":null,\"designationInInvestComp\":null,\"guardianName\":null,\"guardianRelationship\":null,\"guardianTelephoneNo\":null,\"guardianMobileNo\":null,\"guardianFaxNo\":null,\"guardianPanNo\":null,\"guardianEmailId\":null},\"clientDealerPerTradeLimits\":null,\"clientDealerProductMappings\":null,\"clientDealerOrderTypeMappings\":null,\"clientDealerTradingLimits\":null,\"clientDepositoryDetail\":{\"activeStatus\":\"A\",\"id\":53493,\"depositoryAccount1\":1301510000074402,\"depositoryAccount2\":null,\"depositoryAccount3\":null,\"parentId\":null,\"recordType\":null},\"corporateDetail\":null,\"corporateOwnershipDetails\":null,\"displayName\":\"Subash Khatiwada\",\"blockedDate\":null,\"remarks\":\"\",\"parentId\":null,\"recordType\":null,\"collateralByEntities\":null,\"shortSellMode\":0,\"onlineOrOffline\":1,\"panNumber\":null,\"onlineFundTransfer\":null,\"collateralCalculationMode\":1,\"isMarginLendingClient\":false,\"clientRiskType\":\"Medium Risk\"},\"security\":{\"id\":2876,\"exchangeSecurityId\":2925,\"marketProtectionPercentage\":0,\"divisor\":100,\"boardLotQuantity\":1,\"tickSize\":1},\"accountType\":1,\"cpMemberId\":0,\"buyOrSell\":1},\"orderPlacedBy\":2,\"exchangeOrderId\":null}";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    res = curl_easy_perform(curl);
  }
  curl_easy_cleanup(curl);
  return (int)res;
}