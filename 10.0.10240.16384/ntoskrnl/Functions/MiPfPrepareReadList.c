// MiPfPrepareReadList 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall MiPfPrepareReadList(_DWORD *a1, _DWORD *a2)
{
  int *v2; // r3
  int result; // r0
  int v4; // r9

  *a2 = 0;
  if ( (a1[4] & 0x180) != 0
    || ((v2 = *(int **)(*a1 + 20), !a1[2]) ? (v4 = *v2) : (v4 = v2[2]), (*(_DWORD *)(v4 + 28) & 0x400) != 0) )
  {
    result = -1073741585;
  }
  else
  {
    result = sub_80196C();
  }
  return result;
}
