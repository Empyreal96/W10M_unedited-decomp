// PspMapSystemDll 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspMapSystemDll(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  unsigned int v9; // r4
  int v11; // r3
  __int64 v12; // r4 OVERLAPPED
  int v13; // r3
  unsigned int v14; // [sp+18h] [bp-30h] BYREF
  int v15; // [sp+1Ch] [bp-2Ch] BYREF
  _DWORD v16[10]; // [sp+20h] [bp-28h] BYREF

  v14 = a4;
  v8 = ObFastReferenceObject((_DWORD *)a2);
  v9 = v8;
  if ( !v8 )
    return sub_7F58CC(0, 1);
  v11 = 0;
  v14 = 0;
  v15 = 0;
  v16[0] = 0;
  v16[1] = 0;
  if ( a3 )
    v11 = 0x20000000;
  HIDWORD(v12) = MmMapViewOfSection(v8, a1, &v14, 0, 0, v16, &v15, 1, v11, 4);
  ObFastDereferenceObject((_DWORD *)a2, v9);
  if ( HIDWORD(v12) == 1073741827 )
  {
    if ( a1 == PsInitialSystemProcess )
    {
LABEL_7:
      if ( a4 )
      {
        v12 = v14;
        v13 = *(_DWORD *)(RtlImageNtHeader(v14) + 52);
        *(_QWORD *)(a2 + 20) = *(__int64 *)((char *)&v12 - 4);
      }
      else if ( *(_DWORD *)(a2 + 20) != v14 )
      {
        HIDWORD(v12) = -1073741823;
      }
      return HIDWORD(v12);
    }
    HIDWORD(v12) = -1073741800;
  }
  if ( v12 >= 0 )
    goto LABEL_7;
  return HIDWORD(v12);
}
