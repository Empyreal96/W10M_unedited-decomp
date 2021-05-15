// sub_548EC4 
 
void sub_548EC4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, ...)
{
  int v9; // r9
  int v10; // r10
  unsigned int v11; // r1
  int v12; // r8
  unsigned int v13; // r0
  unsigned int v14; // r7
  unsigned int v15; // r5
  unsigned int v16; // [sp+14h] [bp+14h] BYREF
  va_list va; // [sp+14h] [bp+14h]
  int v18; // [sp+18h] [bp+18h]
  int v19; // [sp+1Ch] [bp+1Ch]
  int v20; // [sp+20h] [bp+20h]
  int v21; // [sp+24h] [bp+24h]
  va_list va1; // [sp+28h] [bp+28h] BYREF

  va_start(va1, a9);
  va_start(va, a9);
  v16 = va_arg(va1, _DWORD);
  v18 = va_arg(va1, _DWORD);
  v19 = va_arg(va1, _DWORD);
  v20 = va_arg(va1, _DWORD);
  v21 = va_arg(va1, _DWORD);
  v11 = 0;
  v12 = v18;
  while ( 1 )
  {
    v16 = v11;
    v13 = RtlFindNextForwardRunClearCapped((unsigned int *)va1, v11, 0xFFFFFFFF, (unsigned int *)va);
    v14 = v13;
    if ( !v13 )
      break;
    v15 = v16;
    (*(void (__fastcall **)(int, unsigned int, unsigned int, _DWORD))(v9 + 4))(
      v9,
      *(_DWORD *)(v12 + 136) + ((v16 + v10) << 12),
      v13,
      0);
    v11 = v15 + v14;
  }
  JUMPOUT(0x4C95E6);
}
