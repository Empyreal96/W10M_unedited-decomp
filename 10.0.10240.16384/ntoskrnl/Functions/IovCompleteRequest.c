// IovCompleteRequest 
 
int *__fastcall IovCompleteRequest(int a1, char a2)
{
  int v2; // r6
  int v4; // r0
  int v5; // r3
  int v6; // r2
  int v7; // r2
  unsigned int v8; // r0
  int v9; // r0
  int v10; // r3
  int v11; // r5
  int v12; // r3
  char v13; // r2
  bool v14; // zf
  int *result; // r0
  int v16[6]; // [sp+8h] [bp-60h] BYREF
  _DWORD v17[3]; // [sp+20h] [bp-48h] BYREF
  int v18; // [sp+2Ch] [bp-3Ch]
  char v19[56]; // [sp+30h] [bp-38h] BYREF
  int vars4; // [sp+6Ch] [bp+4h]

  v2 = a2;
  v4 = IovpLogStackTrace(a1);
  v5 = IovpDisabledWithoutReboot;
  __dmb(0xBu);
  if ( !v5 )
  {
    if ( *(char *)(a1 + 35) > (char)(*(_BYTE *)(a1 + 34) + 1) || *(_WORD *)a1 != 6 )
      KeBugCheckEx(68, a1, 1071, 0, 0);
    v6 = *(_DWORD *)(a1 + 56);
    if ( v6 )
      KeBugCheckEx(201, 7, v6, a1, 0);
    v7 = *(_DWORD *)(a1 + 24);
    if ( v7 == 259 || v7 == -1 )
      KeBugCheckEx(201, 6, v7, a1, 0);
    v8 = KeGetCurrentIrql(v4);
    if ( v8 > 2 )
    {
      v9 = KeGetCurrentIrql(v8);
      KeBugCheckEx(201, 14, v9, a1, 0);
    }
  }
  v16[5] = vars4;
  IovpCompleteRequest1(a1, v2, v16);
  v10 = IovpDisabledWithoutReboot;
  __dmb(0xBu);
  if ( (!v10 || v16[0]) && *(char *)(a1 + 35) <= *(char *)(a1 + 34) )
  {
    v11 = *(_DWORD *)(a1 + 96);
    v17[2] = v16;
    v12 = *(_DWORD *)(v11 + 36);
    v17[0] = v11;
    v17[1] = v12;
    memmove((int)v19, v11, 0x28u);
    v13 = *(_BYTE *)(v11 + 3);
    if ( *(int *)(a1 + 24) < 0 )
      v14 = (v13 & 0x80) == 0;
    else
      v14 = (v13 & 0x40) == 0;
    if ( !v14 || *(_BYTE *)(a1 + 36) && (*(_BYTE *)(v11 + 3) & 0x20) != 0 )
    {
      v18 = *(_DWORD *)(v11 + 32);
    }
    else
    {
      v18 = 0;
      *(_BYTE *)(v11 + 3) |= 0xE0u;
    }
    *(_DWORD *)(v11 + 32) = IovpLocalCompletionRoutine;
    *(_DWORD *)(v11 + 36) = v17;
  }
  if ( (IopFunctionPointerMask & 2) != 0 )
    result = IopPerfCompleteRequest(a1, v2);
  else
    result = (int *)IopfCompleteRequest(a1, v2);
  return result;
}
