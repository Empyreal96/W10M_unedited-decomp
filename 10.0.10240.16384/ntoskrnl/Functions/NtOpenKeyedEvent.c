// NtOpenKeyedEvent 
 
int __fastcall NtOpenKeyedEvent(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // r0
  char v6; // [sp+10h] [bp-20h]
  _DWORD _18[12]; // [sp+18h] [bp-18h] BYREF

  _18[11] = a4;
  _18[0] = a4;
  _18[10] = a3;
  _18[9] = a2;
  _18[8] = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 && ((unsigned __int8)a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment();
  *a1 = 0;
  result = ObOpenObjectByName(a3, ExpKeyedEventObjectType, v6, 0, a2, 0, _18);
  if ( result >= 0 )
    *a1 = _18[0];
  return result;
}
