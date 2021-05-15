// HdlspPutMore 
 
int __fastcall HdlspPutMore(_BYTE *a1, int a2)
{
  __int64 v3; // r0
  int v4; // r2
  int v5; // r3
  int v6; // r2
  int v7; // r3
  __int64 v8; // r0
  int v9; // r3
  __int64 v10; // r0
  int result; // r0
  unsigned int v12[2]; // [sp+0h] [bp-20h] BYREF
  char v13[24]; // [sp+8h] [bp-18h] BYREF

  v12[0] = -100000;
  v12[1] = -1;
  HdlspPutString("----Press <Enter> for more----", a2);
  LODWORD(v3) = v13;
  HIDWORD(v3) = 10;
  if ( !HdlspGetLine(v3, v4, v5) )
  {
    do
    {
      v7 = *(_DWORD *)(HeadlessGlobals + 24);
      if ( (v7 & 2) == 0 )
        KeDelayExecutionThread(0, 0, v12);
      LODWORD(v8) = v13;
      HIDWORD(v8) = 10;
    }
    while ( !HdlspGetLine(v8, v6, v7) );
  }
  v9 = v13[0] == 3;
  *a1 = v9;
  do
  {
    LODWORD(v10) = v13;
    HIDWORD(v10) = 10;
    result = HdlspGetLine(v10, v6, v9);
  }
  while ( result );
  return result;
}
