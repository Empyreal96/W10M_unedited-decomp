// IoCreateSystemThread 
 
int __fastcall IoCreateSystemThread(__int16 *a1, int a2, int a3, int *a4, int a5, int a6, int a7, int a8)
{
  int v9; // r0
  _DWORD *v13; // r0
  int v14; // r3
  unsigned int v15; // r4
  int v16; // r6

  v9 = *a1;
  if ( v9 != 3 && v9 != 4 )
    KeBugCheckEx(328, 0, a7, (int)a1, 0);
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v14 = 40;
    else
      v14 = 32;
    v13 = (_DWORD *)ExAllocatePoolWithTagPriority(1, 0xCu, 538996553, v14);
  }
  else
  {
    v13 = (_DWORD *)ExAllocatePoolWithTag(1, 12, 538996553);
  }
  v15 = (unsigned int)v13;
  if ( !v13 )
    return -1073741670;
  *v13 = a1;
  v13[1] = a7;
  v13[2] = a8;
  ObfReferenceObject((int)a1);
  v16 = PsCreateSystemThreadEx(a2, a3, a4, a5, a6, (int)IopThreadStart, v15, 0, 0);
  if ( v16 < 0 )
  {
    ObfDereferenceObject((int)a1);
    ExFreePoolWithTag(v15);
  }
  return v16;
}
