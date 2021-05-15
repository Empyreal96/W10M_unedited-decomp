// KiFreezeCurrentProcessor 
 
int __fastcall KiFreezeCurrentProcessor(int a1, int a2, int a3, int a4)
{
  int v4; // r12
  int v5; // lr
  _DWORD v7[28]; // [sp+0h] [bp-B8h] BYREF
  int v8; // [sp+70h] [bp-48h]
  _DWORD *v9; // [sp+74h] [bp-44h]
  int v10; // [sp+78h] [bp-40h]
  __int64 *v11; // [sp+7Ch] [bp-3Ch]
  void *v12; // [sp+80h] [bp-38h]
  unsigned int v13; // [sp+84h] [bp-34h]
  char v14[48]; // [sp+88h] [bp-30h] BYREF
  __int64 savedregs; // [sp+B8h] [bp+0h] BYREF

  v7[24] = a1;
  v7[25] = a2;
  v7[26] = a3;
  v7[27] = a4;
  v8 = v4;
  v9 = v7;
  v10 = v5;
  v11 = &savedregs;
  v12 = &loc_41FFB6;
  v13 = __get_CPSR() | 0x20;
  v7[4] = 0;
  v7[5] = 0;
  return KiFreezeTargetExecution((int)v7, (int)v14);
}
