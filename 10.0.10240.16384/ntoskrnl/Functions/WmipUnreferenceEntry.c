// WmipUnreferenceEntry 
 
signed int __fastcall WmipUnreferenceEntry(int *a1, _DWORD *a2)
{
  int v4; // r0
  unsigned int *v5; // r2
  unsigned int v6; // r5
  signed int v7; // r5
  int v9; // r2
  int v10; // r3
  _DWORD *v11; // r1
  void (__fastcall *v12)(_DWORD *); // r3

  v4 = KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  __dmb(0xBu);
  v5 = a2 + 3;
  do
  {
    v6 = __ldrex(v5);
    v7 = v6 - 1;
  }
  while ( __strex(v7, v5) );
  __dmb(0xBu);
  if ( v7 )
  {
    if ( v7 < 0 )
      KeBugCheckEx(330, 2, (int)a2, 0, 0);
    KeReleaseMutex((int)&WmipSMMutex);
  }
  else
  {
    v9 = *a2;
    v10 = a2[2] | 0x20000000;
    a2[2] = v10;
    if ( v9 && (v10 & 0x10000000) != 0 )
    {
      v11 = (_DWORD *)a2[1];
      if ( *(_DWORD **)(v9 + 4) != a2 || (_DWORD *)*v11 != a2 )
        sub_7D6478(v4, v11);
      *v11 = v9;
      *(_DWORD *)(v9 + 4) = v11;
    }
    KeReleaseMutex((int)&WmipSMMutex);
    v12 = (void (__fastcall *)(_DWORD *))a1[2];
    if ( v12 )
      v12(a2);
    ExFreeToPagedLookasideList(*a1, a2);
  }
  return v7;
}
