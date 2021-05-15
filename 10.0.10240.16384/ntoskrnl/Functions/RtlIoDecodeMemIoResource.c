// RtlIoDecodeMemIoResource 
 
int __fastcall RtlIoDecodeMemIoResource(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r3
  __int64 v6; // kr00_8

  v5 = *(unsigned __int8 *)(a1 + 1);
  if ( v5 != 3 && v5 != 1 )
    return sub_54DF44();
  v6 = *(_QWORD *)(a1 + 8);
  if ( a2 )
  {
    *a2 = HIDWORD(v6);
    a2[1] = 0;
  }
  if ( a3 )
  {
    *a3 = *(_DWORD *)(a1 + 16);
    a3[1] = *(_DWORD *)(a1 + 20);
  }
  if ( a4 )
  {
    *a4 = *(_DWORD *)(a1 + 24);
    a4[1] = *(_DWORD *)(a1 + 28);
  }
  return v6;
}
