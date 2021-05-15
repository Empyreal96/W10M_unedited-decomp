// PopBatteryCheckTriggerAllBatteries 
 
int __fastcall PopBatteryCheckTriggerAllBatteries(int a1)
{
  int result; // r0
  int v3; // r5
  unsigned int v4; // r2

  result = 1;
  if ( (int *)dword_61ED7C != &dword_61ED7C )
  {
    v3 = *(_DWORD *)(dword_61ED7C + 48);
    if ( !v3 || v3 == -1 )
      goto LABEL_3;
    v4 = *(_DWORD *)(dword_61ED7C + 48) / 0xC8u + *(_DWORD *)(a1 + 12) * v3 / 0x64u;
    if ( *(_DWORD *)(dword_61ED7C + 52) > v4 )
      v4 = *(_DWORD *)(dword_61ED7C + 52);
    if ( *(_DWORD *)(dword_61ED7C + 72) <= v4 )
LABEL_3:
      result = sub_7F3788(1);
    else
      result = 0;
  }
  return result;
}
