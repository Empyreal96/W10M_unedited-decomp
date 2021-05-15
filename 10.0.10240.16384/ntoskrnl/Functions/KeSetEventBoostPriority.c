// KeSetEventBoostPriority 
 
__int64 __fastcall KeSetEventBoostPriority(int a1, _DWORD *a2, int a3, int a4)
{
  __int64 v5; // [sp+0h] [bp-10h]
  _DWORD v6[2]; // [sp+8h] [bp-8h] BYREF

  HIDWORD(v5) = a2;
  v6[0] = a3;
  v6[1] = a4;
  if ( !a2 )
    a2 = v6;
  KeSetEventBoostPriorityEx(a1, (int)a2, 0, 0, 0);
  return v5;
}
