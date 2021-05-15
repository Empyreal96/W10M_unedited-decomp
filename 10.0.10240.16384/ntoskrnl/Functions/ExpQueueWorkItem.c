// ExpQueueWorkItem 
 
int __fastcall ExpQueueWorkItem(int a1, int a2, unsigned int a3, int a4)
{
  int v6; // r2
  int v7; // r0
  int v8; // r5
  int v10; // r3
  int v11; // r3
  int v12; // r2
  BOOL v13; // r1
  int v14; // r2
  _DWORD *v15; // r4
  int v16; // r0
  int v17; // r1
  int v18; // r3
  int v21; // [sp+18h] [bp-20h]

  v21 = KfRaiseIrql(2);
  v6 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8);
  if ( a3 >= (unsigned __int16)KeNumberNodes )
    a3 = *(unsigned __int16 *)(v6 + 266);
  v7 = a3;
  if ( a3 >= (unsigned __int16)KeNumberNodes )
    JUMPOUT(0x52D346);
  v8 = (int)*(&KeNodeBlock + (unsigned __int16)a3);
  if ( (_UNKNOWN *)v8 == (_UNKNOWN *)((char *)&KiNodeInit + 384 * (unsigned __int16)a3) )
    return sub_52D328(v7);
  if ( !v8 )
    return sub_52D328(v7);
  v10 = *(_DWORD *)(v8 + 1016);
  __dmb(0xBu);
  v7 = 1;
  if ( (v10 & 1) == 0 )
    return sub_52D328(v7);
  v11 = *(_DWORD *)(v8 + 4 * (a4 + 96));
  if ( (v11 & 1) != 0 || !v11 )
    return sub_52D328(v7);
  v12 = *(_DWORD *)(v11 + 424);
  __dmb(0xBu);
  v13 = (v12 & 0x4000) != 0;
  v14 = v12 & 0x3FFF;
  if ( v13 )
    --v14;
  if ( v14 < (2 * *(_DWORD *)(v11 + 428)) >> 1 )
    return sub_52D328(v7);
  v15 = *(_DWORD **)(v8 + 4 * (a4 + 96));
  if ( ((unsigned __int8)v15 & 1) != 0 )
    v15 = 0;
  KeInsertPriQueue(v15, a1, a2);
  v16 = v15[108];
  v17 = v15[106];
  __dmb(0xBu);
  if ( v17 < (2 * v15[107]) >> 1
    || v17 < v16 && (_DWORD *)v15[2] == v15 + 2 && (v15[1] || (v18 = v15[107], __dmb(0xBu), v18 < 0)) )
  {
    KeSetEvent(v8 + 856, 0, 0);
  }
  KfLowerIrql(v21);
  return 1;
}
