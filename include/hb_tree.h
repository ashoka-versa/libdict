/*
 * hb_tree.h
 *
 * Interface for height balanced tree.
 * Copyright (C) 2001-2008 Farooq Mela.
 *
 * $Id$
 */

#ifndef _HB_TREE_H_
#define _HB_TREE_H_

#include "dict.h"

BEGIN_DECL

struct hb_tree;
typedef struct hb_tree hb_tree;

hb_tree *hb_tree_new(dict_cmp_func key_cmp, dict_del_func key_del,
					 dict_del_func dat_del);
dict	*hb_dict_new(dict_cmp_func key_cmp, dict_del_func key_del,
					 dict_del_func dat_del);
void	 hb_tree_destroy(hb_tree *tree, int del);

int hb_tree_insert(hb_tree *tree, void *key, void *dat, int overwrite);
int hb_tree_probe(hb_tree *tree, void *key, void **dat);
void *hb_tree_search(hb_tree *tree, const void *key);
const void *hb_tree_csearch(const hb_tree *tree, const void *key);
int hb_tree_remove(hb_tree *tree, const void *key, int del);
void hb_tree_empty(hb_tree *tree, int del);
void hb_tree_walk(hb_tree *tree, dict_vis_func visit);
unsigned hb_tree_count(const hb_tree *tree);
unsigned hb_tree_height(const hb_tree *tree);
unsigned hb_tree_mheight(const hb_tree *tree);
unsigned hb_tree_pathlen(const hb_tree *tree);
const void *hb_tree_min(const hb_tree *tree);
const void *hb_tree_max(const hb_tree *tree);

struct hb_itor;
typedef struct hb_itor hb_itor;

hb_itor *hb_itor_new(hb_tree *tree);
dict_itor *hb_dict_itor_new(hb_tree *tree);
void hb_itor_destroy(hb_itor *tree);

int hb_itor_valid(const hb_itor *itor);
void hb_itor_invalidate(hb_itor *itor);
int hb_itor_next(hb_itor *itor);
int hb_itor_prev(hb_itor *itor);
int hb_itor_nextn(hb_itor *itor, unsigned count);
int hb_itor_prevn(hb_itor *itor, unsigned count);
int hb_itor_first(hb_itor *itor);
int hb_itor_last(hb_itor *itor);
int hb_itor_search(hb_itor *itor, const void *key);
const void *hb_itor_key(const hb_itor *itor);
void *hb_itor_data(hb_itor *itor);
const void *hb_itor_cdata(const hb_itor *itor);
int hb_itor_set_data(hb_itor *itor, void *dat, int del);
int hb_itor_remove(hb_itor *itor, int del);

END_DECL

#endif /* !_HB_TREE_H_ */
