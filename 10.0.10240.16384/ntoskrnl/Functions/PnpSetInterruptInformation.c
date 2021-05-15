// PnpSetInterruptInformation 
 
int __fastcall PnpSetInterruptInformation(int a1, int a2, unsigned int a3)
{
  unsigned int *v6; // r0
  unsigned int *v7; // r4
  int v8; // r3
  int v9; // r0
  int result; // r0

  v6 = (unsigned int *)ExAllocatePoolWithTag(1, a3 + 4, 1198550608);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  *v6 = a3;
  memmove((int)(v6 + 1), a2, a3);
  v8 = *(_DWORD *)(a1 + 176);
  v9 = *(_DWORD *)(v8 + 48);
  *(_DWORD *)(v8 + 48) = v7;
  if ( v9 )
    result = sub_818A48();
  else
    result = 0;
  return result;
}
