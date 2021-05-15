// -SmWdCompleteWorkItems@@YAXPAU_PF_QUEUE@@PAXJK@Z 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall SmWdCompleteWorkItems(struct _PF_QUEUE *a1, void *a2, int a3, unsigned int a4)
{
  struct _PF_QUEUE *v5; // r4 OVERLAPPED
  struct _PF_QUEUE **v6; // r2
  _DWORD *v7; // r5
  bool v8; // zf
  int v9; // r3
  struct _PF_QUEUE *varg_r0; // [sp+18h] [bp+8h]
  void *varg_r1; // [sp+1Ch] [bp+Ch]
  int varg_r2[2]; // [sp+20h] [bp+10h] BYREF

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2[0] = a3;
  varg_r2[1] = a4;
  v5 = a1;
  while ( 1 )
  {
    v6 = (struct _PF_QUEUE **)*((_DWORD *)v5 + 1);
    if ( v6 == (struct _PF_QUEUE **)v5 )
      break;
    v7 = *(_DWORD **)v5;
    v8 = *(_DWORD *)v5 == (_DWORD)v6;
    *(_DWORD *)v5 = **(_DWORD **)v5 & 0xFFFFFFF8;
    if ( v8 )
    {
      v9 = 0;
      *(_QWORD *)v5 = *(_QWORD *)(&v5 - 1);
    }
    else
    {
      a1 = *v6;
      *v6 = (struct _PF_QUEUE *)((unsigned int)*v6 & 7 | (8 * ((unsigned int)*v6 >> 3) - 8));
    }
    a1 = (struct _PF_QUEUE *)SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFree(a1, a2, v7, varg_r2);
  }
}
