// SeRegisterElamCertResources 
 
int __fastcall SeRegisterElamCertResources(int a1, int a2, int a3)
{
  int v3; // r3
  int result; // r0
  int v5; // [sp+10h] [bp-20h] BYREF
  int v6; // [sp+14h] [bp-1Ch] BYREF
  int v7[6]; // [sp+18h] [bp-18h] BYREF

  v5 = 0;
  v6 = 0;
  v3 = 4096;
  if ( a3 )
    v3 = 4608;
  v7[0] = (int)L"MSELAMCERTINFOID";
  v7[1] = (int)L"MICROSOFTELAMCERTIFICATEINFO";
  v7[2] = 0;
  result = LdrResSearchResource(a1, (int)v7, 3u, v3, &v6, &v5, 0, 0);
  if ( result >= 0 )
    result = SepParseElamCertResources(v6, v5);
  return result;
}
