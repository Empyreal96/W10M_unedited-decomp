// MmStoreRegister 
 
int MmStoreRegister()
{
  int v0; // r6
  _DWORD *v1; // r0
  unsigned int v2; // r5
  int v3; // r4
  _DWORD *v4; // r0
  unsigned int v5; // r8
  unsigned int v6; // r1
  __int16 *v7; // r2
  unsigned __int64 v8; // r2
  int v9; // r6
  int v11; // [sp+10h] [bp-30h] BYREF
  int v12[11]; // [sp+14h] [bp-2Ch] BYREF

  dword_63F9A4 = 1;
  v0 = dword_64050C;
  __dmb(0xBu);
  if ( !v0 )
    return sub_7BF728();
  __mrc(15, 0, 13, 0, 3);
  v1 = (_DWORD *)ExAllocatePoolWithTag(512, 24, 1884581197);
  v2 = (unsigned int)v1;
  if ( !v1 )
    return -1073741670;
  *v1 = MiSystemPartition;
  KeInitializeEvent((int)(v1 + 1), 0, 0);
  *(_DWORD *)(v2 + 20) = 0;
  v3 = PsCreateSystemThread(&v11, 0x1FFFFF, 0, 0, 0, MiStoreEvictThread, v2);
  if ( v3 < 0 )
  {
    ExFreePoolWithTag(v2);
  }
  else
  {
    v4 = (_DWORD *)ExAllocatePoolWithTag(
                     512,
                     4 * (((dword_681270 & 0x1F) != 0) + ((unsigned int)dword_681270 >> 5) + 2),
                     538996045);
    v5 = (unsigned int)v4;
    if ( v4 )
    {
      *v4 = dword_681270;
      v4[1] = v4 + 2;
      RtlClearAllBits((int)v4);
      v6 = 0;
      v7 = MiSystemPartition;
      do
      {
        if ( v6 < *(_DWORD *)(*((_DWORD *)v7 + 900) + 4) )
          v6 = *(_DWORD *)(*((_DWORD *)v7 + 900) + 4);
        v7 += 2;
        --v0;
      }
      while ( v0 );
      v8 = (unsigned int)dword_640508 + (unsigned __int64)v6;
      if ( v8 > 0x7FFFF )
      {
        v12[2] = 0;
        LODWORD(v8) = 0x7FFFF;
      }
      v9 = MiCreatePagefile(0, 0, 0, v8);
      if ( v9 )
      {
        v3 = MiInsertPageFileInList();
        if ( v3 >= 0 )
        {
          dword_63F9E4 = v5;
          dword_63F9A4 = 254;
          dword_63F99C = *(_WORD *)(v9 + 96) & 0xF;
          ObReferenceObjectByHandle(v11, 0x1FFFFF, PsThreadType, 0, v12, 0);
          dword_63F9B4 = v12[0];
          __dmb(0xBu);
          v9 = 0;
          v5 = 0;
          v3 = 0;
          dword_63F9A0 = 1;
        }
        else
        {
          *(_DWORD *)(v2 + 20) = 1;
        }
      }
      else
      {
        v3 = -1073741670;
        *(_DWORD *)(v2 + 20) = 1;
      }
      if ( v5 )
        ExFreePoolWithTag(v5);
      if ( v9 )
        MiDeletePagefile(v9);
    }
    else
    {
      v3 = -1073741670;
      *(_DWORD *)(v2 + 20) = 1;
    }
    KeSetEvent(v2 + 4, 0, 0);
    ObCloseHandle(v11);
  }
  return v3;
}
