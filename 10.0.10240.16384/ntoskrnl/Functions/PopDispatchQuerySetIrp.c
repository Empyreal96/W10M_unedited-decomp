// PopDispatchQuerySetIrp 
 
int __fastcall PopDispatchQuerySetIrp(_DWORD *a1)
{
  int v2; // r2
  signed int v3; // r0
  int *v4; // r2
  int **v6; // r0

  v2 = a1[24];
  *(_BYTE *)(v2 + 3) |= 1u;
  v3 = ObfReferenceObject(*(_DWORD *)(v2 + 24));
  v4 = a1 + 22;
  if ( a1 == (_DWORD *)PopInrushIrp )
    return sub_54B170(v3, &PopIrpWorkerList, v4);
  v6 = (int **)dword_61E87C;
  *v4 = (int)&PopIrpWorkerList;
  a1[23] = v6;
  if ( *v6 != &PopIrpWorkerList )
    __fastfail(3u);
  *v6 = v4;
  dword_61E87C = (int)(a1 + 22);
  return KeReleaseSemaphore((int)&PopIrpWorkerSemaphore, 0, 1);
}
