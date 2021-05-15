// ViTargetRemovingCheckContiguousMemory 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall __spoils<R0,R2,R3,R12> ViTargetRemovingCheckContiguousMemory(int a1, int a2)
{
  int *v2; // r4
  int result; // r0
  int v4; // r1 OVERLAPPED
  _DWORD *v5; // r2 OVERLAPPED

  v2 = (int *)(a1 + 136);
  if ( *(_DWORD *)(a1 + 136) != a1 + 136 )
  {
    ViBadDriver = a2 + 44;
    VerifierBugCheckIfAppropriate(196, 98, *(_DWORD *)(a2 + 48), a1, *(_DWORD *)(a1 + 128));
  }
  while ( 1 )
  {
    result = *v2;
    if ( (int *)*v2 == v2 )
      break;
    *(_QWORD *)&v4 = *(_QWORD *)result;
    if ( *(_DWORD *)(*(_DWORD *)result + 4) != result || *v5 != result )
      __fastfail(3u);
    *v5 = v4;
    *(_DWORD *)(v4 + 4) = v5;
    VfPoolDelayFreeIfPossible(result, 0);
  }
  return result;
}
