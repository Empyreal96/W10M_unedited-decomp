// MiZeroAllPageFiles 
 
// local variable allocation has failed, the output may be wrong!
int MiZeroAllPageFiles()
{
  unsigned int v0; // r6
  unsigned int i; // r5
  unsigned int *v2; // r7
  _DWORD *v3; // r0
  int v4; // r4 OVERLAPPED
  int (__fastcall *v5)(int); // r3
  unsigned int v7[10]; // [sp+10h] [bp-78h] BYREF
  int v8[20]; // [sp+38h] [bp-50h] BYREF

  VfZeroAllPagesRunning = 1;
  v0 = dword_64050C;
  __dmb(0xBu);
  for ( i = v0; i; --i )
  {
    v2 = &v7[4 * i - 2];
    KeInitializeEvent((int)v2, 0, 0);
    v7[i - 1] = (unsigned int)v2;
    if ( (*(_WORD *)(*(_DWORD *)&MiSystemPartition[2 * i + 1798] + 96) & 0x40) != 0
      || (v3 = (_DWORD *)ExAllocatePoolWithTag(512, 24, 2002414925), (v4 = (int)v3) == 0) )
    {
      KeSetEvent((int)v2, 0, 0);
    }
    else
    {
      v3[4] = *(_DWORD *)&MiSystemPartition[2 * i + 1798];
      v3[5] = v2;
      if ( i == 1 )
      {
        KeSetEvent((int)v2, 0, 0);
        MiZeroPageFile(v4);
      }
      else
      {
        v5 = MiZeroPageFile;
        *(_QWORD *)(v4 + 8) = *(_QWORD *)(&v4 - 1);
        *v3 = 0;
        ExQueueWorkItem(v3, 0);
      }
    }
  }
  if ( v0 > 1 )
    KeWaitForMultipleObjects(v0, v7, 0, 0, 0, 0, 0, v8);
  VfZeroAllPagesRunning = 0;
  return 1;
}
