// MiObtainSectionForDriver 
 
int __fastcall MiObtainSectionForDriver(unsigned __int16 *a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r5
  unsigned __int16 *v7; // r3
  int v9; // r10
  int v10; // r4
  int v12; // r4
  int v13; // r2
  _BYTE *v14; // r0
  _BYTE *v15; // r4
  int v17[9]; // [sp+4h] [bp-24h] BYREF

  v17[1] = (int)a4;
  v6 = 0;
  v7 = a1;
  v17[0] = 0;
  *a4 = 0;
  v9 = __mrc(15, 0, 13, 0, 3);
  while ( 1 )
  {
    v10 = PsLoadedModuleList;
    while ( (int *)v10 != &PsLoadedModuleList )
    {
      if ( RtlEqualUnicodeString(v7, (unsigned __int16 *)(v10 + 36), 1) )
        return sub_7CDA28();
      v10 = *(_DWORD *)v10;
      v7 = a1;
    }
    if ( v6 )
      break;
    MmReleaseLoadLock(v9 & 0xFFFFFFC0);
    v12 = MiCreateSectionForDriver(a2, a3, v17);
    MmAcquireLoadLock(v12);
    if ( v12 < 0 )
      return v12;
    v6 = v17[0];
    v13 = *(_DWORD *)(*(_DWORD *)MiSectionControlArea(v17[0]) + 36);
    v7 = a1;
    if ( (*(_WORD *)(v13 + 30) & 0x8000) != 0 )
    {
      v7 = a1;
      if ( *(_DWORD *)(v13 + 16) == 1 )
      {
        if ( (a3 & 1) == 0 )
        {
          v12 = -1073741800;
LABEL_13:
          ObDereferenceObjectDeferDelete(v6);
          return v12;
        }
        v7 = a1;
      }
    }
  }
  v14 = (_BYTE *)ExAllocatePoolWithTag(512, 92, 1682730317);
  v15 = v14;
  if ( !v14 )
  {
    v12 = -1073741670;
    goto LABEL_13;
  }
  memset(v14, 0, 92);
  *((_DWORD *)v15 + 13) = 0x1000000;
  *((_WORD *)v15 + 28) = 1;
  *((_DWORD *)v15 + 19) = -2;
  *((_DWORD *)v15 + 15) = v6;
  *a4 = v15;
  return 0;
}
