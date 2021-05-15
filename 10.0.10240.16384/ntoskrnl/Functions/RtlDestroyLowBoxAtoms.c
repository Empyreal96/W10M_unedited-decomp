// RtlDestroyLowBoxAtoms 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlDestroyLowBoxAtoms(int a1, int a2)
{
  int result; // r0
  unsigned int v4; // r7
  _DWORD *i; // r10
  _DWORD *v6; // r5
  _DWORD *v7; // t1
  int v8; // r8
  int *v9; // r4
  int v10; // r2
  int *v11; // r0
  int *v12; // r1 OVERLAPPED
  int **v13; // r2 OVERLAPPED

  result = RtlpLockAtomTable();
  if ( result )
  {
    v4 = 0;
    for ( i = (_DWORD *)(a1 + 24); v4 < *(_DWORD *)(a1 + 20); ++v4 )
    {
      v7 = (_DWORD *)*i++;
      v6 = v7;
LABEL_4:
      while ( 1 )
      {
        v8 = (int)v6;
        if ( !v6 )
          break;
        v9 = (int *)v6[2];
        v6 = (_DWORD *)*v6;
        if ( v9 != (int *)(v8 + 8) )
        {
          v10 = a2;
          while ( 1 )
          {
            v11 = v9;
            if ( v9[2] == v10 )
            {
              *(_QWORD *)&v12 = *(_QWORD *)v9;
              v9 = (int *)v9[1];
              if ( *(int **)(*v11 + 4) != v11 || *v13 != v11 )
                sub_514930();
              *v13 = v12;
              v12[1] = (int)v13;
              RtlpFreeAtom(v11);
              if ( RtlpDereferenceAtom(v8, v8 + 8, a1) )
                goto LABEL_4;
              v10 = a2;
            }
            v9 = (int *)*v9;
            if ( v9 == (int *)(v8 + 8) )
              goto LABEL_4;
          }
        }
      }
    }
    result = RtlpUnlockAtomTable(a1);
  }
  return result;
}
