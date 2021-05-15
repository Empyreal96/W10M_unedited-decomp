// PpmWmiRegisterInfo 
 
int __fastcall PpmWmiRegisterInfo(int a1, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  int result; // r0
  int (**v7)[4]; // r8
  int v8; // r10
  _DWORD *v9; // lr
  int v10; // r1
  int v11; // r2
  int v12; // r3

  if ( a3 < 0x128 )
    return sub_818808();
  memset((_BYTE *)a4, 0, 296);
  v7 = &PpmWmiGuidList;
  *(_DWORD *)(a4 + 16) = 8;
  v8 = 8;
  v9 = (_DWORD *)(a4 + 20);
  do
  {
    v10 = (**v7)[1];
    v11 = (**v7)[2];
    v12 = (**v7)[3];
    *v9 = (**v7)[0];
    v9[1] = v10;
    v9[2] = v11;
    v9[3] = v12;
    --v8;
    v9[4] = v7[2];
    v9[5] = v7[1];
    v9[6] = 244;
    v9 += 7;
    v7 += 3;
  }
  while ( v8 );
  *(_DWORD *)a4 = 296;
  *(_WORD *)(a4 + 244) = 50;
  result = RtlStringCbPrintfW((_WORD *)(a4 + 246), a3 - 246, (int)L"%s%d", (int)L"PPM_Processor_");
  if ( result >= 0 )
    result = 0;
  *a5 = 296;
  return result;
}
