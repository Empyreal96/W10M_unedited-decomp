// WmipProcessEvent 
 
int __fastcall WmipProcessEvent(unsigned int *a1, int a2, int a3)
{
  unsigned int v3; // r6
  int v4; // r10
  unsigned int *v6; // r4
  int v7; // r9
  int v8; // r7
  _DWORD *v9; // r8
  int v10; // r6
  int v11; // r3
  void (__fastcall *v12)(unsigned int *, _DWORD); // r3
  _DWORD *v14; // [sp+8h] [bp-28h]
  unsigned int *v15; // [sp+Ch] [bp-24h]

  v3 = (unsigned int)a1;
  v4 = a3;
  v15 = a1;
  if ( (a1[11] & 0x2000) != 0 )
    return sub_7D641C();
  v6 = a1;
  if ( (a1[11] & 0x80) != 0 )
    v6 = (unsigned int *)WmipIncludeStaticNames(a1, *a1);
  v7 = WmipFindGEByGuid(v6 + 6, 1);
  if ( v7 )
  {
    v8 = 0;
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    v9 = *(_DWORD **)(v7 + 24);
    if ( v9 != (_DWORD *)(v7 + 24) )
    {
      v10 = a2;
      do
      {
        v14 = (_DWORD *)*v9;
        if ( ObReferenceObjectSafe((int)(v9 - 8)) )
        {
          v11 = v9[18];
          if ( (v11 & 2) != 0 )
          {
            v12 = (void (__fastcall *)(unsigned int *, _DWORD))v9[4];
            if ( v12 )
              v12(v6, v9[5]);
          }
          else if ( WmipWriteWnodeToObject((int)(v9 - 8), v6, v10, v11) < 0 )
          {
            v8 = -1073741823;
          }
          ObfDereferenceObject((int)(v9 - 8));
        }
        v9 = v14;
      }
      while ( v14 != (_DWORD *)(v7 + 24) );
      v3 = (unsigned int)v15;
      v4 = a3;
    }
    KeReleaseMutex((int)&WmipSMMutex);
    WmipUnreferenceEntry(&WmipGEChunkInfo, v7);
  }
  else
  {
    v8 = -1073741163;
  }
  if ( v4 )
    ExFreePoolWithTag(v3);
  if ( v6 != (unsigned int *)v3 )
  {
    if ( v6 )
      ExFreePoolWithTag((unsigned int)v6);
  }
  return v8;
}
