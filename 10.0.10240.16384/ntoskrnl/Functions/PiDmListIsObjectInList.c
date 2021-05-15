// PiDmListIsObjectInList 
 
BOOL __fastcall PiDmListIsObjectInList(int a1, int a2, int a3)
{
  return *(_DWORD *)(PiDmListDefs[5 * a1 + 3] + a3) != 0;
}
