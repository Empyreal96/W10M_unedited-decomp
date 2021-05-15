// CmpFireCleanupNotifications 
 
int __fastcall CmpFireCleanupNotifications(int result, int a2)
{
  int v2; // r5
  _DWORD *i; // r4
  int v4; // r6
  int v5; // [sp+8h] [bp-20h] BYREF
  int v6; // [sp+Ch] [bp-1Ch]
  int v7; // [sp+10h] [bp-18h]
  int vars8; // [sp+30h] [bp+8h]
  int anonymous0; // [sp+34h] [bp+Ch]

  anonymous0 = a2;
  v2 = result;
  vars8 = result;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  for ( i = *(_DWORD **)(result + 36); i != (_DWORD *)(v2 + 36); i = (_DWORD *)*i )
  {
    v4 = i[6];
    v5 = v2;
    v6 = i[8];
    result = (*(int (__fastcall **)(_DWORD, int, int *))(v4 + 28))(*(_DWORD *)(v4 + 24), 40, &v5);
  }
  return result;
}
