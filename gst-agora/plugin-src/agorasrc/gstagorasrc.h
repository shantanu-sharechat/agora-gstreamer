/*
 * GStreamer
 * Copyright (C) 2005 Thomas Vander Stichele <thomas@apestaart.org>
 * Copyright (C) 2005 Ronald S. Bultje <rbultje@ronald.bitfreak.net>
 * Copyright (C) 2020 Niels De Graef <niels.degraef@gmail.com>
 * Copyright (C) 2021 Ubuntu <<user@hostname.org>>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, the contents of this file may be used under the
 * GNU Lesser General Public License Version 2.1 (the "LGPL"), in
 * which case the following provisions apply instead of the ones
 * mentioned above:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * */

#ifndef __GST_AGORASRC_H__
#define __GST_AGORASRC_H__

#include <gst/gst.h>
#include <gst/base/gstpushsrc.h>

#include "agorac.h"

G_BEGIN_DECLS

/* #defines don't like whitespacey bits */
#define GST_TYPE_AGORASRC \
  (gst_agorasrc_get_type())
#define GST_AGORASRC(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_AGORASRC,Gstagorasrc))
#define GST_AGORASINK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_AGORASRC,GstagorasrcClass))
#define GST_IS_AGORASRC(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_AGORASRC))
#define GST_IS_AGORASRC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_AGORASRC))

#define GST_TYPE_AGORASRC (gst_agorasrc_get_type())

G_DECLARE_FINAL_TYPE (Gstagorasrc, gst_agorasrc,
    GST, PLUGIN_TEMPLATE, GstPushSrc)

#define MAX_STRING_LEN  1024

typedef struct _Gstagorasrc
{
  GstPushSrc element;

  GstPad  *srcpad;

  gboolean verbose;
  gboolean audio;

  AgoraIoContext_t* agora_ctx;

  GQueue*      media_queue;

  gboolean     is_segment_sent;

  gchar app_id[MAX_STRING_LEN];
  gchar channel_id[MAX_STRING_LEN];
  gchar remote_user_id[MAX_STRING_LEN];

} Gstagorasrc;

G_END_DECLS

#endif /* __GST_AGORASRC_H__ */
