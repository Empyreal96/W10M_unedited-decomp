// PopFindNextSystemPowerState 
 
int __fastcall PopFindNextSystemPowerState(int a1, int a2, _BYTE *a3)
{
  int result; // r0
  int v5; // r5

  result = 1;
  dword_61EC80 = dword_61EC84;
  if ( dword_61EC84 == 1 )
  {
    v5 = dword_61EC6C;
    if ( dword_61EC6C < 0 && *a3 )
    {
      *a3 = 0;
      dword_61EC80 = a1;
      dword_61EC6C = v5 & 0xEFFFFFFF;
    }
    else if ( a2 && a1 == 5 )
    {
      dword_61EC80 = 5;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
