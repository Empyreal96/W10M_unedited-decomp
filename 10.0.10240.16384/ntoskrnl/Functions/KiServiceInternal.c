// KiServiceInternal 
 
int __fastcall KiServiceInternal(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r12
  unsigned int v5; // r0
  unsigned int v6; // r12
  int v7; // r1
  int result; // r0
  unsigned int v9; // r1
  int (__fastcall *v10)(int, int, int, int); // [sp+0h] [bp-88h]
  int v11; // [sp+4h] [bp-84h]
  int v12; // [sp+8h] [bp-80h]
  int v13; // [sp+8h] [bp-80h]
  int v14; // [sp+Ch] [bp-7Ch]
  __int64 v15; // [sp+10h] [bp-78h]
  char v16; // [sp+13h] [bp-75h]
  int v17; // [sp+18h] [bp-70h]
  int v18; // [sp+1Ch] [bp-6Ch]
  int v19; // [sp+20h] [bp-68h]
  int v20; // [sp+24h] [bp-64h]
  int v21; // [sp+28h] [bp-60h]
  int v22; // [sp+2Ch] [bp-5Ch]
  int v23; // [sp+30h] [bp-58h]
  int v24; // [sp+34h] [bp-54h]
  int v25; // [sp+38h] [bp-50h]
  int v26; // [sp+3Ch] [bp-4Ch]
  int v27; // [sp+40h] [bp-48h]
  int v28; // [sp+44h] [bp-44h]
  int v29; // [sp+48h] [bp-40h]
  int v30; // [sp+4Ch] [bp-3Ch]
  int v31; // [sp+50h] [bp-38h]
  int v32; // [sp+54h] [bp-34h]
  int v33; // [sp+58h] [bp-30h]
  int v34; // [sp+5Ch] [bp-2Ch]

  __get_CPSR();
  HIBYTE(v15) = 0;
  __enable_irq();
  v5 = v4;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(unsigned __int8 *)(v6 + 346);
  *(_DWORD *)((char *)&v15 + 3) = v7;
  v12 = *(_DWORD *)(v6 + 96);
  *(_BYTE *)(v6 + 346) = 0;
  result = KiSystemService(
             v5,
             v7,
             v12,
             0,
             v10,
             v11,
             v12,
             v14,
             v15,
             SHIDWORD(v15),
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             a1,
             a2,
             a3,
             a4);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v9 + 96) = v13;
  *(_BYTE *)(v9 + 346) = v16;
  return result;
}
