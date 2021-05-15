// CmpCreateEvent 
 
int __fastcall CmpCreateEvent(int a1, _DWORD *a2, _DWORD *a3)
{
  int v5; // r4
  int result; // r0
  int v7[12]; // [sp+8h] [bp-30h] BYREF

  v7[2] = 24;
  v7[3] = 0;
  v7[4] = 0;
  v7[6] = 0;
  v7[7] = 0;
  v7[5] = 576;
  v5 = ZwCreateEvent();
  if ( v5 >= 0 && (v5 = ObReferenceObjectByHandle(*a2, 2031619, 0, 0, v7, 0), *a3 = v7[0], v5 < 0) )
    result = sub_7C35D4();
  else
    result = v5;
  return result;
}
