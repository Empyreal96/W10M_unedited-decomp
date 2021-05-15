// WmipQueueLegacyEtwWork 
 
int __fastcall WmipQueueLegacyEtwWork(_DWORD *a1, _DWORD *a2, int a3)
{
  int result; // r0
  int v7; // r6
  _DWORD *v8; // r1
  int v9; // r3
  _DWORD *v10; // r1

  result = WmipReferenceEntry((int)a2);
  if ( a3 )
    return sub_819D3C(result);
  v7 = a2[24];
  if ( v7 )
  {
    v10 = *(_DWORD **)(v7 + 16);
    *a1 = v7 + 12;
    a1[1] = v10;
    if ( *v10 != v7 + 12 )
      __fastfail(3u);
    *v10 = a1;
    *(_DWORD *)(v7 + 16) = a1;
  }
  else
  {
    v8 = (_DWORD *)a2[26];
    *a1 = a2 + 25;
    a1[1] = v8;
    if ( (_DWORD *)*v8 != a2 + 25 )
      __fastfail(3u);
    *v8 = a1;
    a2[26] = a1;
    v9 = a2[2];
    if ( (v9 & 0x10) == 0 )
    {
      a2[2] = v9 | 0x10;
      result = ExQueueWorkItem((_DWORD *)(a2[16] + 16), 1);
    }
  }
  return result;
}
