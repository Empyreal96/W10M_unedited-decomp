// SmIoRequestComplete 
 
int __fastcall SmIoRequestComplete(int a1, _DWORD *a2, int a3, int *a4)
{
  __int64 v4; // r0
  int v6; // r2

  HIDWORD(v4) = *a2;
  v6 = a4[1];
  if ( (v4 & 0x700000000i64) != 0 )
  {
    if ( (BYTE4(v4) & 7) == 2 )
    {
      HIDWORD(v4) = (unsigned __int16)v6;
      a4[1] = (unsigned __int16)v6;
    }
  }
  else
  {
    if ( *a4 < 0 )
      *a4 = -1073741670;
    a4[1] = (v6 & 1) != 0;
  }
  if ( a3 < 0 )
    return KeSetEvent(a3, 1, 0);
  LODWORD(v4) = a3 | 0x80000000;
  MiStoreModifiedWriteComplete(v4);
  return MiStoreFreeWriteSupport((_DWORD *)(a3 | 0x80000000), (int)MiSystemPartition);
}
