// MiSegmentDelete 
 
int __fastcall MiSegmentDelete(unsigned int *a1)
{
  unsigned int v1; // r8
  unsigned int v3; // r6
  int v4; // r7
  int v5; // r1
  _DWORD *v6; // r0
  int v8; // r4
  int v9; // r0
  int v10; // [sp+0h] [bp-20h]

  v1 = *a1;
  v3 = a1[7];
  v4 = (v3 >> 7) & 1;
  v10 = *(_DWORD *)(*a1 + 8);
  if ( !v4 || (v3 & 0x20) != 0 )
    v5 = 0;
  else
    v5 = (int)(a1 + 20);
  v6 = (_DWORD *)MiPrepareSegmentForDeletion((int)a1, v5);
  if ( v4 )
  {
    if ( (v10 & 0x2000) != 0 )
      return sub_801230(v6);
    MiReleaseControlAreaWaiters(v6);
  }
  else if ( (dword_682604 & 0x400001) != 0 )
  {
    MiLogSectionCreate(a1, 0);
  }
  v8 = MiDeleteSegmentPages((int *)a1);
  if ( v4 )
  {
    if ( (v3 & 2) == 0 )
    {
      v9 = ObFastReplaceObject(a1 + 8, 0);
      ObfDereferenceObject(v9);
    }
    if ( (v3 & 0x20) != 0 )
      ExFreePoolWithTag(*(_DWORD *)(v1 + 40));
  }
  else
  {
    MiDeletePageFileSectionNodes((unsigned int)a1);
  }
  ExFreePoolWithTag(v1);
  MiDereferenceControlAreaProbe((int)a1);
  return v8;
}
