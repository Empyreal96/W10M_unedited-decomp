// RtlGetVersion 
 
int __fastcall RtlGetVersion(int *a1, int a2, int a3, int a4)
{
  int v5; // r3
  unsigned __int8 v6; // r3
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  a1[1] = 10;
  a1[3] = 10240;
  a1[4] = 2;
  v5 = *a1;
  a1[2] = 0;
  if ( v5 == 284 || v5 == 292 )
  {
    *((_WORD *)a1 + 138) = BYTE1(CmNtCSDVersion);
    v6 = CmNtCSDVersion;
    *((_WORD *)a1 + 140) = 0;
    *((_BYTE *)a1 + 282) = 0;
    *((_WORD *)a1 + 139) = v6;
    if ( InitializationPhase )
    {
      if ( RtlGetNtProductType(v8) )
        *((_BYTE *)a1 + 282) = v8[0];
      *((_WORD *)a1 + 140) = MEMORY[0xFFFF92D0];
      if ( *a1 == 292 )
        return sub_7E9BA8();
    }
    *((_BYTE *)a1 + 283) = 0;
  }
  return 0;
}
