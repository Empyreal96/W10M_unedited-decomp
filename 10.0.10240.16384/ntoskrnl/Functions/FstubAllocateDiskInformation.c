// FstubAllocateDiskInformation 
 
int __fastcall FstubAllocateDiskInformation(int a1, unsigned int *a2)
{
  int v4; // r0
  unsigned int v5; // r4
  int v6; // r5
  unsigned __int64 v7; // r2
  __int64 v8; // r0
  int v9; // r0
  int v11; // r5

  v4 = ExAllocatePoolWithTag(512, 56, 1114927942);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  if ( FstubGetDiskGeometry(a1, (_DWORD *)(v4 + 8)) < 0 )
    JUMPOUT(0x7D5DAE);
  v6 = *(_DWORD *)(v5 + 28);
  if ( v6 && (v7 = *(_QWORD *)(v5 + 32)) != 0 )
  {
    v8 = *(unsigned int *)(v5 + 28);
    *(_DWORD *)v5 = a1;
    *(_DWORD *)(v5 + 4) = v6;
    *(_QWORD *)(v5 + 48) = (unsigned int)_rt_udiv64((unsigned int)v8, v7);
    v9 = ExAllocatePoolWithTag(516, v6, 1114927942);
    if ( !v9 )
      return sub_7D5DAC();
    *(_DWORD *)(v5 + 40) = v9;
    *a2 = v5;
    v11 = 0;
  }
  else
  {
    ExFreePoolWithTag(v5);
    v11 = -1073741661;
  }
  return v11;
}
