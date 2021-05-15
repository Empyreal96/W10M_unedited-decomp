// KiDisplayBlueScreen 
 
int __fastcall KiDisplayBlueScreen(int a1)
{
  int v2; // r4
  char *v3; // r6
  unsigned int v4; // r1
  int v5; // r0
  unsigned __int16 i; // r5
  int *v7; // r3
  char *v8; // r2
  int v9; // r1
  unsigned __int16 *v10; // r6
  unsigned __int16 *v11; // r5
  int v12; // r0
  int v13; // r9
  int result; // r0
  int *v15; // r4
  int v16; // r5
  int v17[2]; // [sp+10h] [bp-1C0h] BYREF
  unsigned __int16 *v18; // [sp+18h] [bp-1B8h] BYREF
  unsigned __int16 *v19; // [sp+1Ch] [bp-1B4h]
  unsigned __int16 v20; // [sp+20h] [bp-1B0h]
  __int16 v21; // [sp+22h] [bp-1AEh]
  _WORD *v22; // [sp+24h] [bp-1ACh]
  char v23[16]; // [sp+48h] [bp-188h] BYREF
  char v24; // [sp+58h] [bp-178h] BYREF
  _WORD v25[144]; // [sp+B0h] [bp-120h] BYREF

  KiEnableHeadlessBlueScreen();
  v2 = KiBugCheckDriver;
  if ( KiBugCheckDriver || (KiDumpParameterImages(0, &dword_624904, 4, 0), (v2 = KiBugCheckDriver) != 0) )
  {
    if ( *(_WORD *)v2 == 30 && !memcmp(*(_DWORD *)(v2 + 4), (unsigned int)L"VerifierExt.sys", 30) )
      v2 = 0;
  }
  v22 = v25;
  v21 = 256;
  if ( KeGetBugMessageText(KiBugCheckData, (int)v17) )
  {
    v3 = (char *)v17[1];
    v4 = LOWORD(v17[0]);
  }
  else
  {
    RtlStringCbPrintfExA(v23, 0xBu, v17, 0, 0, "0x%08x");
    v3 = v23;
    v4 = (unsigned __int16)(v17[0] - (_DWORD)v23);
  }
  if ( v4 >= 0x7F )
    v4 = 127;
  v5 = 0;
  if ( v4 )
  {
    for ( i = 0; i < v4; v5 = ++i )
      v25[v5] = v3[v5];
  }
  v25[v5] = 0;
  v20 = 2 * v5;
  v7 = (int *)&v18;
  v8 = &v24;
  v9 = 4;
  do
  {
    *((_WORD *)v7 + 8) = 20;
    *((_WORD *)v7 + 9) = 22;
    v7[5] = (int)v8;
    v7 += 2;
    v8 += 22;
    --v9;
  }
  while ( v9 );
  v10 = 0;
  v11 = 0;
  v18 = 0;
  v19 = 0;
  v12 = InbvAcquireDisplayOwnership();
  v13 = KiBugCheckData;
  BgpFwAcquireLock(v12);
  if ( (dword_619018 & 2) != 0 )
  {
    BgpFwDisplayBugCheckScreen(v13, &dword_624904, v2, &v18, a1);
    v10 = v18;
    v11 = v19;
  }
  BgpFwReleaseLock();
  result = IoSaveBugCheckProgress(128);
  if ( v10 && v11 )
  {
    KiHeadlessDisplayString(L"\r\n", 6);
    KiHeadlessDisplayString(*((_DWORD *)v10 + 1), *v10);
    KiHeadlessDisplayString(L"\r\n", 6);
    KiHeadlessDisplayString(*((_DWORD *)v11 + 1), *v11);
    KiHeadlessDisplayString(L"\r\n", 6);
    KiHeadlessDisplayString(v22, v20);
    if ( KiBugCheckDriver )
    {
      KiHeadlessDisplayString(L"\r\n", 6);
      KiHeadlessDisplayString(*(_DWORD *)(KiBugCheckDriver + 4), *(unsigned __int16 *)KiBugCheckDriver);
    }
    KiHeadlessDisplayString(L"\r\n", 6);
    KiHeadlessDisplayString(L"\r\n", 6);
    v15 = (int *)&v18;
    v16 = 4;
    do
    {
      KiHeadlessDisplayString(v15[5], *((unsigned __int16 *)v15 + 8));
      KiHeadlessDisplayString(L"\r\n", 6);
      v15 += 2;
      --v16;
    }
    while ( v16 );
    result = KiHeadlessDisplayString(L"\r\n", 6);
  }
  return result;
}
