// KsepGetModuleInfoByName 
 
int __fastcall KsepGetModuleInfoByName(unsigned __int16 *a1, unsigned int *a2, _DWORD *a3, int a4)
{
  int v6; // r3
  int v7; // r4
  unsigned int v8; // r6
  _DWORD *v9; // r4
  int v10; // r3
  unsigned __int16 *v12; // [sp+0h] [bp-20h] BYREF
  unsigned int *v13; // [sp+4h] [bp-1Ch]
  _DWORD v14[6]; // [sp+8h] [bp-18h] BYREF

  v12 = a1;
  v13 = a2;
  v14[0] = a3;
  v14[1] = a4;
  if ( !a1 || !a3 || !a2 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)v14, a1);
  v7 = RtlUnicodeStringToAnsiString((unsigned __int16 *)&v12, (unsigned __int16 *)v14, 1, v6);
  if ( v7 >= 0 )
  {
    v8 = 0;
    if ( *a2 )
    {
      v9 = a2 + 1;
      while ( 1 )
      {
        RtlInitAnsiString((unsigned int)v14, (unsigned int)v9 + *((unsigned __int16 *)v9 + 13) + 28);
        if ( !RtlCompareString((unsigned __int16 *)v14, (unsigned __int16 *)&v12, 1) )
          break;
        ++v8;
        v9 += 71;
        if ( v8 >= *a2 )
          goto LABEL_9;
      }
      v10 = v9[2];
      v7 = 0;
      *a3 = v10;
    }
    else
    {
LABEL_9:
      v7 = -1073741275;
    }
  }
  if ( v13 )
    RtlFreeAnsiString(&v12);
  return v7;
}
