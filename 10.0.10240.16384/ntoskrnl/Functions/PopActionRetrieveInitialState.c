// PopActionRetrieveInitialState 
 
int __fastcall PopActionRetrieveInitialState(_DWORD *a1, _DWORD *a2, _DWORD *a3, _BYTE *a4)
{
  _DWORD *v7; // r5
  int v8; // r2
  int v9; // r2
  int v10; // r1
  int result; // r0
  unsigned int v12; // r1
  int v13; // r3

  v7 = a1;
  if ( dword_61EC64 == 4 || dword_61EC64 == 5 || dword_61EC64 == 6 )
  {
    *a1 = 6;
    *a2 = 6;
  }
  else if ( dword_61EC64 == 7 )
  {
    *a2 = 5;
    a1 = (_DWORD *)PopVerifySystemPowerState(a2, 0);
  }
  else
  {
    v8 = PopPolicy;
    *a2 = *(_DWORD *)(PopPolicy + 72);
    v9 = *(_DWORD *)(v8 + 68);
    if ( v9 > *a1 )
      *a1 = v9;
  }
  if ( *v7 > *a2 )
    *a2 = *v7;
  *a4 = 1;
  v10 = dword_61EC6C;
  if ( *v7 == 6 || dword_61EC6C < 0 && (dword_61EC74 == 2 || dword_61EC74 == 1) )
    *a4 = 0;
  result = PopFastS4Check(a1, v10);
  if ( result )
  {
    *v7 = *a2;
    v12 = dword_61EC6C & 0xEFFFFFFF;
    dword_61EC6C &= 0xEFFFFFFF;
  }
  if ( (v12 & 0x10000000) != 0 )
    v13 = *v7;
  else
    v13 = *a2;
  *a3 = v13;
  return result;
}
